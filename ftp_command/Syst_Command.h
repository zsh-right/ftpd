#ifndef __SYST_COMMAND_H__
#define __SYST_COMMAND_H__

#include "common/Util.h"
#include "container/Command.h"
#include "container/Register_Action.h"

class Syst_Command : public Command {
 public:
  virtual void exec(const ACE_SOCK_Stream &stream, const string &cmd) override;
};

#endif  // __SYST_COMMAND_H__