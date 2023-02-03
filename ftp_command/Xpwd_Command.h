#ifndef __XPWD_COMMAND_H__
#define __XPWD_COMMAND_H__

#include "container/Command.h"
#include "container/Register_Action.h"

#define COMMAND_SIZE 80

class Xpwd_Command: public Command
{
public:
    virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd)override;
};

#endif // __XPWD_COMMAND_H__