#include "Command.h"
#include "common/Ftp_Msg.h"
#include "common/User.h"

#include <unordered_map>

using namespace std;

extern unordered_map<int, User*>handler_user;

bool Command::is_user_login(const ACE_SOCK_Stream &stream)
{
    if (handler_user.find(stream.get_handle()) == handler_user.end() ||
        handler_user[stream.get_handle()]->get_status() == 0)
    {
        stream.send(USR_UNLOGIN, ACE_OS::strlen(USR_UNLOGIN), 0);
        return false;
    }
    return true;
}