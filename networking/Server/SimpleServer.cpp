#include "SimpleServer.hpp"

tserve::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg){
    listenSocket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
};

tserve::ListeningSocket * tserve::SimpleServer::get_socket(){
    
}
