#ifndef simpleserver_hpp
#define simpleserver_hpp

#include "../Sockets/tservesockets.hpp"
namespace tserve{
    class SimpleServer {
        private:
            ListeningSocket * listenSocket;
            virtual void accepter() = 0;
            virtual void handler() = 0; 
            virtual void responder() = 0; 
        public:
            SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
            virtual void launch() = 0;
            ListeningSocket * get_socket();

    };
}

#endif
