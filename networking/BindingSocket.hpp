#ifndef bindingsocket_hpp
#define bindingsocket_hpp

#include "simplesocket.hpp"

namespace tserve {
    class BindingSocket: public tserve::SimpleSocket {

        public: 
            BindingSocket(int domain, int service, int protocol, int port, u_long interface);
            int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif
