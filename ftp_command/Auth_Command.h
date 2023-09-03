#ifndef __AUTH_COMMAND_H__
#define __AUTH_COMMAND_H__

#include "container/Command.h"
#include "container/Register_Action.h"

class Auth_Command : public Command {
 public:
  virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd) override;
};

#endif  // __AUTH_COMMAND_H__