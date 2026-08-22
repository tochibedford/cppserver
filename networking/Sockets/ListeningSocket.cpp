#include "ListeningSocket.hpp"

tserve::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklog): BindingSocket(domain, service, protocol, port, interface){
    backlog = bklog;
    int listeningStatus = start_listening();
    test_connection(listeningStatus);
}

int tserve::ListeningSocket::start_listening(){
    return listen(get_sock(), backlog);
}
