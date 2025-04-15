#include <unistd.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <sstream>
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include "ShxCalculator.h"

const int PORT = 8080;

std::string handle_get_request() {
    using namespace std::chrono;

    ShxCalculator calc;
    const int n = 10;
    const int ARRAY_SIZE = 100000;

    std::vector<double> values;
    values.reserve(ARRAY_SIZE);

    auto start_time = steady_clock::now();

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        values.push_back(calc.FuncA(n));
    }

    std::sort(values.begin(), values.end());

    auto end_time = steady_clock::now();
    double duration_sec = duration_cast<duration<double>>(end_time - start_time).count();

    std::ostringstream response_body;
    response_body << "Computation Time: " << duration_sec << " seconds\n";
    return response_body.str();
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "HTTP server is running on port " << PORT << std::endl;

    while (true) {
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);

        if (strncmp(buffer, "GET", 3) == 0) {
            std::string response_body = handle_get_request();
            std::string response =
                "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n" + response_body;

            send(new_socket, response.c_str(), response.size(), 0);
        }

        close(new_socket);
    }

    return 0;
}
