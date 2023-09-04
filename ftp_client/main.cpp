#include <ace/OS.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "ffcs_ftp_client.cpp"
#include "util.h"
using namespace std;

string name;
string password;

int ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  std::string ftp_host;
  int ftp_port;

  std::cout << "ftp>input your host:";
  std::cin >> ftp_host;

  std::cout << "ftp>input your port:";
  std::cin >> ftp_port;

  std::string ftp_local_dir = "/home/scutech/ftp_server/";
  std::string ftp_remote_dir = "/home/scutech/client/";

  std::string ftp_local_file_tmp = "TaskThread.cpp";
  std::string ftp_local_file = "TaskThread.cpp";
  FTPClient ftp_client;
  do
  {
    // cout<<"ftp>input ip:"<<endl;
    // string ip;
    // cin>>ip;
    // cout<<"ftp>input server port:"<<endl;
    // int port;
    // cin>>port;

    ftp_client.setAddr(ftp_host, ftp_port);
    if (!ftp_client.connect())
    {
      return 0;
    }
    std::string ftp_user;
    std::string ftp_pwd;
    cout << "ftp>input your user name:" << endl;
    cin >> ftp_user;
    cout << "ftp>input your password:" << endl;
    cin >> ftp_pwd;
    ftp_client.setUserInfo(ftp_user, ftp_pwd);
  } while (!ftp_client.LogoIn());
  cin.get();
  do
  {
    cout << "ftp>";
    std::string parameter;
    getline(cin, parameter);
    vector<string> cmd;
    Stringsplit(parameter, " ", cmd);
    if (cmd[0] == "chld" && cmd.size() > 1)
    {
      ftp_client.ChangeLocalDir(cmd[1]);
    }
    else if (cmd[0] == "cd" && cmd.size() > 1)
    {
      ftp_client.ChangeRemoteDir(cmd[1]);
    }
    else if (cmd[0] == "quit")
    {
      ftp_client.LogoOut();
    }
    else if (cmd[0] == "put")
    {
      ftp_client.PutFile(cmd[1]);
    }
    else if (cmd[0] == "rename")
    {
      ftp_client.ReName(cmd[1], cmd[2]);
    }
    else if (cmd[0] == "get")
    {
      ftp_client.GetFile(cmd[1]);
    }
    else if (cmd[0] == "syst")
    {
      ftp_client.GetSysInfo();
    }
    else if (cmd[0] == "ls")
    {
      std::string path = cmd.size() > 1 ? cmd[1] : "";
      std::string pathlist;
      ftp_client.List(pathlist, path);
    }
    else if (cmd[0] == "user" && cmd.size() > 1)
    {
      name.clear();
      name = cmd[1];
    }
    else if (cmd[0] == "pass" && cmd.size() > 1)
    {
      password.clear();
      password = cmd[1];
      ftp_client.setUserInfo(name, password);
      ftp_client.LogoIn();
    }
    else if (cmd[0] == "pwd")
    {
      ftp_client.pwd_cmd();
    }
    else if (cmd[0] == "port")
    {
      ftp_client.port_cmd();
    }
    else if (cmd[0] == "pasv")
    {
      ftp_client.pasv_cmd();
    }
    else if (cmd[0] == "type")
    {
      ftp_client.type_cmd();
    }
    else if (cmd[0] == "dele" && cmd.size() > 1)
    {
      ftp_client.dele_cmd(cmd[1]);
    }
    else if (cmd[0] == "mkdir" && cmd.size() > 1)
    {
      ftp_client.mkd_cmd(cmd[1]);
    }
    else if (cmd[0] == "rmd" && cmd.size() > 1)
    {
      ftp_client.rmd_cmd(cmd[1]);
    }
    else if (cmd[0] == "cdup")
    {
      ftp_client.ChangeRemoteDir("..");
    }
    else if (cmd[0] == "size" && cmd.size() > 1)
    {
      ftp_client.size_cmd(cmd[1]);
    }
    else if (cmd[0] == "xpwd")
    {
      ftp_client.xpwd_cmd();
    }

  } while (true);
  return 0;
}
