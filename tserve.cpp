#include "networking/Server/SimpleServer.hpp"
#include <unistd.h>

const int BUFFER_SIZE = 30000;

int main(){
    class TestServer: public tserve::SimpleServer {
        private:
            char buffer[BUFFER_SIZE] = {0};
            int new_socket;
            void accepter(){
                struct sockaddr_in address = get_socket()->get_address();
                int addrlen = sizeof(address);
                new_socket = accept(get_socket()->get_sock(), (struct sockaddr *) &address, (socklen_t *) &addrlen);
                read(new_socket, buffer, BUFFER_SIZE);
            };
            void handler(){
                std::cout << buffer << std::endl;
            };
            void responder(){
                char *hello = "hello from server";
                write(new_socket, hello, strlen(hello));
                close(new_socket);
            };
        public:
            TestServer();
            virtual void launch(){
                while(true){
                    std::cout<< "===== WAITING =====" << std::endl;
                    accepter();
                    handler();
                    responder();
                }
            }

    };
}
