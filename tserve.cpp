#include "networking/Sockets/ListeningSocket.hpp"

int main(){
    std::cout << "Starting..." << std::endl;
    std::cout << "Binding Socket..." << std::endl;
    tserve::BindingSocket bs = tserve::BindingSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);
    std::cout << "Listening Socket..." << std::endl;
    tserve::ListeningSocket ls = tserve::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    std::cout << "Success!" << std::endl;
}
