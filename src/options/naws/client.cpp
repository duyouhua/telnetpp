#include "telnetpp/options/naws/client.hpp"
#include "telnetpp/options/naws/detail/protocol.hpp"

namespace telnetpp { namespace options { namespace naws {

// ==========================================================================
// CONSTRUCTOR
// ==========================================================================
client::client()
  : client_option(telnetpp::options::naws::detail::option)
{
}

// ==========================================================================
// HANDLE_SUBNEGOTIATION
// ==========================================================================
std::vector<telnetpp::token> client::handle_subnegotiation(
    byte_stream const &content)
{
    if (content.size() == sizeof(window_dimension) + sizeof(window_dimension))
    {
        window_dimension width  = content[0] << 8 | content[1];
        window_dimension height = content[2] << 8 | content[3];

        return on_window_size_changed(width, height);
    }
    else
    {
        return {};
    }
}

}}}
