#ifndef listeningsocket_hpp
#define listeningsocket_hpp

#include "BindingSocket.hpp"

namespace tserve {
    class ListeningSocket: public BindingSocket{
        private:
            int backlog;
        public:
            ListeningSocket(int domain,   int service, int protocol, int port, u_long interface, int bklg);
            int start_listening();
    };
}

#endif
