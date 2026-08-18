#ifndef listeningsocket_hpp
#define listeningsocket_hpp

#include "BindingSocket.hpp"

namespace tserve {
    class ListeningSocket: public BindingSocket{
        private:
            int backlog;
            int listening;
        public:
            ListeningSocket(int domain,  int service, int protocol, int port, u_long interface, int bklg);
            void start_listening();
    };
}

#endif
