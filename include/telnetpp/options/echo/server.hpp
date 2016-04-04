#pragma once

#include "telnetpp/options/subnegotiationless_server.hpp"
#include "telnetpp/options/echo.hpp"

namespace telnetpp { namespace options { namespace echo {

using server = telnetpp::options::subnegotiationless_server<
    telnetpp::options::echo::option
>;

}}}
