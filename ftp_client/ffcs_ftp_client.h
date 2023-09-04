#ifndef FTP_CLIENT_ACE_H
#define FTP_CLIENT_ACE_H

#include <ace/Acceptor.h>
#include <ace/Connector.h>
#include <ace/OS.h>
#include <ace/Reactor.h>
#include <ace/SOCK_Acceptor.h>
#include <ace/SOCK_Connector.h>
#include <ace/SOCK_Stream.h>
#include <stdio.h>

#include <iostream>
#include <sstream>
#include <string>

#define MAX_CONN_TIMEOUT_SECOND 3      /*TCP connection timeout in second.*/
#define MAX_CONN_TIMEOUT_MILLISECOND 0 /*TCP connection timeout in ms.*/

#define MAX_RECV_TIMEOUT_SECOND 1      /*TCP connection timeout in second.*/
#define MAX_RECV_TIMEOUT_MILLISECOND 0 /*TCP connection timeout in ms.*/

#define MAX_BUFSIZE 1024

class FTPClient {
 public:
  FTPClient();
  FTPClient(const std::string &remote_ip, const u_short remote_port,
            int os_type = OS_DEFAULT);
  virtual ~FTPClient();
  bool connect();
  bool LogoIn();
  bool LogoOut();
  void setUserInfo(std::string user_name, std::string password);
  bool GetSysInfo();
  bool Noop();

  void setAddr(std::string ip, int port);
  bool ChangeLocalDir(const std::string &dirname);
  bool ChangeRemoteDir(const std::string dirname);

  bool PutFile(const std::string &filename);
  bool GetFile(const std::string &filename);

  bool List(std::string &pathlist, const std::string &pathname = "");
  bool NList(std::string &pathlist, const std::string &pathname = "");

  bool ReName(const std::string &srcname, const std::string &dstname);

  bool pwd_cmd();
  bool port_cmd();
  bool pasv_cmd();
  bool type_cmd();
  bool dele_cmd(const std::string &filename);
  bool mkd_cmd(const std::string &filename);
  bool rmd_cmd(const std::string &dir);
  bool size_cmd(const std::string &filename);
  bool auth_cmd();
  bool xpwd_cmd();

 private:
  bool Recv(std::string &response);
  bool Send(const std::string &command);

  std::string user_name_, pass_word_;
  ACE_INET_Addr remote_addr_;
  ACE_SOCK_Connector connector_;
  ACE_SOCK_Stream peer_;

  int os_type_;

 public:
  enum {
    OS_DEFAULT = 0,
    OS_LINUX = 1,
    OS_WIN32 = 2,
    OS_AIX = 3,
    OS_HP_UNIX = 4,
    OS_SUNOS = 5
  };
};

#endif
