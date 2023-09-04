#ifndef __HEADERS_H__
#define __HEADERS_H__

#include "ftp_command/Auth_Command.h"
#include "ftp_command/Cdup_Command.h"
#include "ftp_command/Cwd_Command.h"
#include "ftp_command/Dele_Command.h"
#include "ftp_command/List_Command.h"
#include "ftp_command/Mkd_Command.h"
#include "ftp_command/Pass_Command.h"
#include "ftp_command/Pasv_Command.h"
#include "ftp_command/Port_Command.h"
#include "ftp_command/Pwd_Command.h"
#include "ftp_command/Quit_Command.h"
#include "ftp_command/Retr_Command.h"
#include "ftp_command/Rmd_Command.h"
#include "ftp_command/Rnfr_Command.h"
#include "ftp_command/Rnto_Command.h"
#include "ftp_command/Size_Command.h"
#include "ftp_command/Stor_Command.h"
#include "ftp_command/Syst_Command.h"
#include "ftp_command/User_Command.h"
#include "ftp_command/Xpwd_Command.h"

REGISTER(Dele_Command);
REGISTER(Rnto_Command);
REGISTER(Rnfr_Command);
REGISTER(Rmd_Command);
REGISTER(Mkd_Command);
REGISTER(Size_Command);
REGISTER(Pwd_Command);
REGISTER(Auth_Command);
REGISTER(Xpwd_Command);
REGISTER(Stor_Command);
REGISTER(Retr_Command);
REGISTER(Quit_Command);
REGISTER(Cdup_Command);
REGISTER(Cwd_Command);
REGISTER(User_Command);
REGISTER(List_Command);
REGISTER(Pass_Command);
REGISTER(Syst_Command);
REGISTER(Pasv_Command);
REGISTER(Port_Command);
#endif  // __HEADERS_H__