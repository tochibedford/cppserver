#ifndef simplesocket_hpp
#define simplesocket_hpp

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

namespace tserve {
    class SimpleSocket {
        private:
            struct sockaddr_in address;
            int sock;
        public: 
            SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
            virtual ~SimpleSocket() = default;
            virtual int connect_to_network(
                int sock,
                struct sockaddr_in address
            ) = 0;
            void test_connection(int);
            //Getter funtions
            struct sockaddr_in get_address();
            int get_sock();
    };
}

#endif
