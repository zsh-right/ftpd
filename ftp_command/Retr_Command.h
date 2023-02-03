#ifndef __RETR_COMAND_H__
#define __RETR_COMAND_H__

#include "container/Command.h"
#include "container/Register_Action.h"

class Retr_Command: public Command
{
public:
    virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd) override;
};

#endif // __RETR_COMAND_H__