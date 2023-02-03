#include <stdio.h>
#include <stdlib.h>
#include <ace/OS.h>
#include <ace/FILE_Addr.h>
#include <ace/FILE_Connector.h>
#include <ace/FILE_IO.h>
#include <ace/OS_NS_string.h>
#include <ace/OS_NS_stdio.h>

#include "ffcs_ftp_client.h"

#define BEGINPORT 10000
#define ENDPORT 15000
#define LOCAL_IP "127.0.0.1"


ACE_INET_Addr ftp_data_addr;

ACE_SOCK_Stream stream;
ACE_SOCK_Connector connector;
ACE_SOCK_Acceptor acceptor;


FTPClient::FTPClient()
{
	this->os_type_ = OS_DEFAULT;
}
FTPClient::FTPClient(const string &remote_ip, const u_short remote_port, int os_type)
{
	this->remote_addr_.set((u_short)remote_port, remote_ip.c_str());
	this->os_type_ = os_type;
}

FTPClient::~FTPClient()
{
	peer_.close_writer();
	peer_.close_reader();
	peer_.close();
}

bool FTPClient::connect()
{
	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);
	if (this->connector_.connect(this->peer_, this->remote_addr_, &tv) == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) %p\n"), ACE_TEXT("connection failed")), false);
		return false;
	}
	std::string ftp_resp;

	if (!this->Recv(ftp_resp))
	{
		return false;
	}
	ACE_DEBUG((LM_DEBUG, "%s", ftp_resp));
	if (ftp_resp.substr(0, 3) != "220")
	{
		return false;
	}
	ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) connected to (%s:%d)\n\n"), this->remote_addr_.get_host_addr(), this->remote_addr_.get_port_number()));
	return true;
}

/*接收FTP应答*/
bool FTPClient::Recv(std::string &response)
{
	std::string line;
	ACE_Time_Value tv(MAX_RECV_TIMEOUT_SECOND, MAX_RECV_TIMEOUT_MILLISECOND);

	response.clear();

	while (true)
	{
		char c;
		switch (this->peer_.recv_n(&c, 1, &tv))
		{
		case 0:
		default:
			line.append(1, c);
			break;
		}

		if ('\n' == c)
		{
			response = line;
			break;
		}
	}
	std::cout << response << std::endl;
	return true;
}

/*发送FTP命令*/
bool FTPClient::Send(const std::string &command)
{
	std::cout << command;
	if (static_cast<ssize_t>(command.length()) == this->peer_.send_n(command.c_str(), command.length()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*登录*/
bool FTPClient::LogoIn()
{

	std::stringstream USER, PASS, SYST;
	string ftp_resp;

	USER << "USER " << this->user_name_ << "\n";
	std::cout<<USER.str()<<std::endl;
	if (this->Send(USER.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "331")
		{
			return false;
		}
	}

	PASS << "PASS " << this->pass_word_ << "\n";
	if (this->Send(PASS.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "230")
		{
			return false;
		}

		/*AIX返回的Login指令有3个*/
		if (this->os_type_ == OS_AIX)
		{
			if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "230")
			{
				return false;
			}
			if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "230")
			{
				return false;
			}
		}
	}

	return true;
}

/*退出*/
bool FTPClient::LogoOut()
{
	std::stringstream QUIT;
	std::string ftp_resp;

	QUIT << "QUIT"
		 << "\n";
	if (this->Send(QUIT.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "221")
		{
			return false;
		}
	}
	return true;
}

void FTPClient::setUserInfo(string user_name,string password)
{
	this->user_name_ = user_name;
	this->pass_word_ = password;
}

/*获得远程系统信息*/
bool FTPClient::GetSysInfo()
{
	std::stringstream SYST;
	std::string ftp_resp;

	SYST << "SYST"<< "\n";
	if (this->Send(SYST.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "215")
		{
			return false;
		}
	}

	return true;
}

/*防空闲*/
bool FTPClient::Noop()
{
	std::stringstream NOOP;
	std::string ftp_resp;

	NOOP << "NOOP"
		 << "\n";
	if (this->Send(NOOP.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "200")
		{
			return false;
		}
	}

	return true;
}

void FTPClient::setAddr(string ip,int port)
{
	this->remote_addr_.set((u_short)port, ip.c_str());
}

/*修改本地路径，影响下载的文件所保存的路径 或者 上传的本地文件所在路径*/
bool FTPClient::ChangeLocalDir(const std::string &dirname)
{
	return ACE_OS::chdir(dirname.c_str()) < 0 ? false : true;
}

/*修改远程路径，影响下载的远程文件所在路径 或者 上传的文件所保存的路径*/
bool FTPClient::ChangeRemoteDir(const std::string dirname)
{
	std::stringstream CWD;
	std::string ftp_resp;

	CWD << "CWD " << dirname << "\n";
	if (this->Send(CWD.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "250")
		{
			return false;
		}
	}
	this->pwd_cmd();
	return true;
}

/*上传文件*/
bool FTPClient::PutFile(const std::string &filename)
{
	std::stringstream STOR;
	std::string ftp_resp;

	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);

	int d0, d1, d2, d3, p0, p1;
	std::stringstream ip;

	ACE_FILE_Info file_info;
	ACE_FILE_IO file_put;
	ACE_FILE_Connector file_con;
	char file_cache[MAX_BUFSIZE];
	int file_size, all_size;

	if (ACE_OS::access(filename.c_str(), F_OK) < 0)
		return false; /*文件不存在*/

	if(!this->pasv_cmd()){
		return false;
	}

	STOR << "STOR " << filename << "\n";
	if (this->Send(STOR.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "150")
		{
			return false;
		}
	}

	if (file_con.connect(file_put, ACE_FILE_Addr(filename.c_str()), &tv, ACE_Addr::sap_any, 0, O_RDONLY, ACE_DEFAULT_FILE_PERMS) == -1)
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n to %s"), ACE_TEXT("open"), filename), false);

	if (file_put.get_info(&file_info) == -1)
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("get_info")), false);

	all_size = 0;
	while ((all_size < file_info.size_) && ((file_size = file_put.recv(file_cache, sizeof(file_cache))) > 0))
	{
		all_size += stream.send_n(file_cache, file_size);
	}
	file_put.close();

	stream.close_writer();
	stream.close_reader();
	stream.close();

	if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "226")
	{
		return false;
	}

	if (all_size != file_info.size_)
	{
		std::cout << "Send " << filename << "(" << file_info.size_ << ") fail! Only sent (" << all_size << ")" << std::endl;
		return false;
	}

	std::cout << "Send " << filename << "(" << all_size << ") OK!" << std::endl
			  << std::endl;
	return true;
}

/*下载文件*/
bool FTPClient::GetFile(const std::string &filename)
{
	std::stringstream RETR;
	std::string ftp_resp;
	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);

	ACE_FILE_IO file_put;
	ACE_FILE_Connector file_con;
	char file_cache[MAX_BUFSIZE];
	int file_size, all_size;
	
	if(!this->pasv_cmd()){
		return false;
	}
	
	RETR << "RETR " << filename << "\n";
	if (this->Send(RETR.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "150")
		{
			cout<<ftp_resp<<endl;
			return false;
		}
	}

	if (file_con.connect(file_put, ACE_FILE_Addr(filename.c_str()), &tv, ACE_Addr::sap_any, 0, O_RDWR | O_CREAT, ACE_DEFAULT_FILE_PERMS) == -1)
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n to %s"), ACE_TEXT("open"), filename), false);

	all_size = 0;
	while ((file_size = stream.recv(file_cache, sizeof(file_cache))) > 0)
	{
		all_size += file_put.send_n(file_cache, file_size);
	}
	file_put.close();

	stream.close_writer();
	stream.close_reader();
	stream.close();

	if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "226")
	{
		return false;
	}

	std::cout << "Recv " << filename << "(" << all_size << ") OK!" << std::endl
			  << std::endl;
	return true;
}

/*名字列表*/
bool FTPClient::NList(std::string &pathlist, const std::string &pathname)
{
	std::stringstream PASV, NLST;
	std::string ftp_resp;

	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);

	int d0, d1, d2, d3, p0, p1;
	std::stringstream ip;
	ACE_INET_Addr ftp_data_addr;

	ACE_SOCK_Stream stream;
	ACE_SOCK_Connector connector;

	char file_cache[MAX_BUFSIZE] = {0};
	int file_size;

	PASV << "PASV"
		 << "\n";
	if (this->Send(PASV.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "227")
		{
			return false;
		}
	}

	ftp_resp = ftp_resp.substr(ftp_resp.find_last_of('(') + 1, (ftp_resp.find_last_of(')') - ftp_resp.find_last_of('(') - 1));

	if (sscanf(ftp_resp.c_str(), "%d,%d,%d,%d,%d,%d", &d0, &d1, &d2, &d3, &p0, &p1) == -1)
		return false;
	ip << d0 << "." << d1 << "." << d2 << "." << d3;
	ftp_data_addr.set((p0 << 8) + p1, ip.str().c_str());

	if (connector.connect(stream, ftp_data_addr, &tv) == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) %p\n"), ACE_TEXT("connection failed")), false);
	}

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) connected to (%s:%d)\n\n"), this->remote_addr_.get_host_addr(), this->remote_addr_.get_port_number()));

	if (pathname.empty())
	{
		NLST << "NLST"
			 << "\n";
	}
	else
	{
		NLST << "NLST " << pathname << "\n";
	}
	if (this->Send(NLST.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "150")
		{
			return false;
		}
	}

	pathlist.clear();
	while ((file_size = stream.recv(file_cache, sizeof(file_cache) - 1)) > 0)
	{
		pathlist.append(file_cache);

		ACE_OS::memset(file_cache, 0x00, sizeof(file_cache));
	}

	stream.close_writer();
	stream.close_reader();
	stream.close();

	if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "226")
	{
		return false;
	}

	return true;
}

/*列表*/
bool FTPClient::List(std::string &pathlist, const std::string &pathname)
{
	std::stringstream  LIST;
	std::string ftp_resp;


	char file_cache[MAX_BUFSIZE] = {0};
	int file_size;

	this->pasv_cmd();

	LIST << "LIST " << pathname << "\n";
	if (this->Send(LIST.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "150")
		{
			return false;
		}
	}

	pathlist.clear();
	while ((file_size = stream.recv(file_cache, MAX_BUFSIZE)) > 0)
	{
		pathlist.append(file_cache);
		cout<<pathlist<<endl;
		pathlist.clear();
		ACE_OS::memset(file_cache, 0x00, sizeof(file_cache));
	}

	stream.close_writer();
	stream.close_reader();
	stream.close();

	if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "226")
	{
		return false;
	}

	return true;
}

/*更名*/
bool FTPClient::ReName(const std::string &srcname, const std::string &dstname)
{
	std::stringstream RNFR, RNTO;
	std::string ftp_resp;

	RNFR << "RNFR " << srcname << "\n";
	if (this->Send(RNFR.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "350")
		{
			return false;
		}
	}

	RNTO << "RNTO " << dstname << "\n";
	if (this->Send(RNTO.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "250")
		{
			return false;
		}
	}

	return true;
}

bool FTPClient::pwd_cmd()
{
	std::stringstream PWD;
	std::string ftp_resp;

	PWD << "PWD" << "\n";
	if (this->Send(PWD.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "257")
		{
			return false;
		}
	}
	return true;
}

bool FTPClient::port_cmd()
{
	std::stringstream PORT;
	string ftp_resp;
	PORT << "PORT ";
	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);
	int pPort;
    for(pPort = BEGINPORT; pPort < ENDPORT; pPort++) {
        if(ftp_data_addr.set(pPort) == -1) {
            continue;
        }
        if(acceptor.open(ftp_data_addr)==-1) {
            continue;
        }
        break;
    }
    if (pPort >= ENDPORT) {
        return false;
    }
    PORT<<"("<<LOCAL_IP<<","<<(pPort>>8)<<","<<(pPort & 0xFF)<<").\n";
    this->peer_.send(PORT.str().c_str(), ACE_OS::strlen(PORT.str().c_str()),0);
    if (acceptor.accept(stream) == -1) {
        ACE_DEBUG((LM_DEBUG, "监听失败！\n"));
		return false;
    }
	acceptor.close();
	return true;
}

bool FTPClient::pasv_cmd()
{
	std::stringstream PASV;
	string ftp_resp;
	PASV << "PASV"<< "\n";

	ACE_Time_Value tv(MAX_CONN_TIMEOUT_SECOND, MAX_CONN_TIMEOUT_MILLISECOND);

	int d0, d1, d2, d3, p0, p1;
	std::stringstream ip;

	char file_cache[MAX_BUFSIZE] = {0};
	int file_size;
	if (this->Send(PASV.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "227")
		{
			return false;
		}
	}
	ftp_resp = ftp_resp.substr(ftp_resp.find_last_of('(') + 1, (ftp_resp.find_last_of(')') - ftp_resp.find_last_of('(') - 1));

	if (sscanf(ftp_resp.c_str(), "%d,%d,%d,%d,%d,%d", &d0, &d1, &d2, &d3, &p0, &p1) == -1)
		return false;
	ip << d0 << "." << d1 << "." << d2 << "." << d3;
	ftp_data_addr.set((p0 << 8) + p1, ip.str().c_str());
	if (connector.connect(stream, ftp_data_addr, &tv) == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("(%P|%t) %p\n"), ACE_TEXT("connection failed")), false);
	}

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) connected to (%s:%d)\n\n"), this->remote_addr_.get_host_addr(), this->remote_addr_.get_port_number()));
	return true;
}

bool FTPClient::type_cmd()
{
	std::stringstream TYPE;
	string ftp_resp;
	TYPE << "TYPE I"<< "\n";
	if (this->Send(TYPE.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "200")
		{
			return false;
		}
	}
	return true;
}

bool FTPClient::dele_cmd(const std::string &filename)
{
	std::stringstream DELE;
	string ftp_resp;
	DELE<< "DELE "<<filename<<"\n";
	if (this->Send(DELE.str())) {
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "250") {
			return false;
		}
	}
	return true;
}

bool FTPClient::mkd_cmd(const std::string &filename)
{
	std::stringstream MDK;
	string ftp_resp;
	MDK<< "MKD "<<filename<<"\n";
	if (this->Send(MDK.str())) {
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "275") {
			return false;
		}
	}
	return true;
}

bool FTPClient::rmd_cmd(const std::string &dir)
{
	std::stringstream RMD;
	string ftp_resp;
	RMD<< "RMD "<<dir<<"\n";
	if (this->Send(RMD.str())) {
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "250") {
			return false;
		}
	}
	return true;
}

bool FTPClient::size_cmd(const std::string &filename)
{
	std::stringstream SIZE;
	string ftp_resp;
	SIZE<< "SIZE "<<filename<<"\n";
	if (this->Send(SIZE.str())) {
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "213") {
			return false;
		}
	}
	return true;
}

bool FTPClient::auth_cmd()
{
	std::stringstream AUTH;
	string ftp_resp;
	AUTH << "AUTH "<< "\n";
	if (this->Send(AUTH.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "502")
		{
			return false;
		}
	}
	return true;
}

bool FTPClient::xpwd_cmd()
{
	std::stringstream XPWD;
	string ftp_resp;
	XPWD << "XPWD "<< "\n";
	if (this->Send(XPWD.str()))
	{
		if (!this->Recv(ftp_resp) || ftp_resp.substr(0, 3) != "257")
		{
			return false;
		}
	}
	return true;
}




