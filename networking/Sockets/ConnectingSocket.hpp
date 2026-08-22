#ifndef connectingsocket_hpp
#define connectingsocket_hpp

#include "simplesocket.hpp"

namespace tserve {
    class ConnectingSocket: public tserve::SimpleSocket {

        public: 
            ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
            int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif
