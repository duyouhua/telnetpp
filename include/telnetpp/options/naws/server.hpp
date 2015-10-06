#ifndef TELNETPP_OPTIONS_NAWS_SERVER
#define TELNETPP_OPTIONS_NAWS_SERVER

#include "telnetpp/options/naws.hpp"
#include "telnetpp/negotiation.hpp"
#include "telnetpp/token.hpp"
#include <boost/signals2/signal.hpp>
#include <vector>

namespace telnetpp { namespace options { namespace naws {

class server {
public :
    //* =====================================================================
    /// \brief Activates the option.
    //* =====================================================================
    std::vector<telnetpp::token> activate();
    
    //* =====================================================================
    /// \brief Deactivates the option.
    //* =====================================================================
    std::vector<telnetpp::token> deactivate();

    //* =====================================================================
    /// \brief Returns true iff the option is active.
    //* =====================================================================
    bool is_active() const;

    //* =====================================================================
    /// \brief Makes a request of the option
    //* =====================================================================
    std::vector<telnetpp::token> negotiate(telnetpp::u8 request);
    
    boost::signals2::signal<void ()> on_state_changed;
    
private :
    enum class state
    {
        inactive,
        activating,
        active,
        deactivating,
    };
    
    state state_ = state::inactive;
};

}}}

#endif
