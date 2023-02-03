#ifndef __PASS_COMMAND_H__
#define __PASS_COMMAND_H__

#include "container/Command.h"
#include "common/Util.h"
#include "container/Register_Action.h"

class Pass_Command: public Command
{
public:
    virtual void exec(const ACE_SOCK_STREAM &stream, const string &cmd) override;
};


#endif // __PASS_COMMAND_H__