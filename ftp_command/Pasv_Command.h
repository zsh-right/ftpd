#ifndef __PASV_COMMAND_H__
#define __PASV_COMMAND_H__

#include "container/Command.h"
#include "common/Util.h"
#include "container/Register_Action.h"

class Pasv_Command: public Command
{
public:
    virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd) override;
};

#endif // __PASV_COMMAND_H__