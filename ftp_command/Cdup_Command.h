#ifndef __CDUP_COMMAND_H__
#define __CDUP_COMMAND_H__

#include "container/Command.h"
#include "container/Register_Action.h"

class Cdup_Command: public Command
{
public:
    virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd)override;
};

#endif // __CDUP_COMMAND_H__