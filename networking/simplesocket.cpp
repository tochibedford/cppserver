#include "simplesocket.hpp"

tserve::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    //Establish connection
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

void tserve::SimpleSocket::test_connection(int item_to_test){
    if(item_to_test < 0 ){
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in tserve::SimpleSocket::get_address(){
    return address;
}

int tserve::SimpleSocket::get_sock(){
    return sock;
}

int tserve::SimpleSocket::get_connection(){
    return connection;
}

void tserve::SimpleSocket::set_connection(int con){
    connection = con;
}


