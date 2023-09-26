// #include "socket.h"




// void Socket::wait()
// {
//    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//         perror("Socket creation failed");
//         return;
//     }

//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = INADDR_ANY;
//     address.sin_port = htons(PORT);

//     // Forcefully attaching socket to the port 8080
//     if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
//         perror("Bind failed");
//         return;
//     }
    
//     if (listen(server_fd, 3) < 0) {
//         perror("Listen failed");
//         return;
//     }

//     if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
//         perror("Accept failed");
//         return;
//     }
//     int t = 2;
//     while (t > 0) {
//         --t;
//         valread = read(new_socket, buffer, 1024);
//         if (valread > 0) {
//             printf("Received message: %s\n", buffer);
//             memset(buffer, 0, sizeof(buffer));
//         }
//     }
// }



// void Socket::act()
// {
//     int sock = 0;
//     struct sockaddr_in server_address;
    
//     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
//         perror("Socket creation error");
//         return;
//     }

//     server_address.sin_family = AF_INET;
//     server_address.sin_port = htons(PORT);

//     if (inet_pton(AF_INET, SERVER_ADDR, &server_address.sin_addr) <= 0) {
//         perror("Invalid address/ Address not supported");
//         return;
//     }

//     if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
//         perror("Connection Failed");
//         return;
//     }
//     int t = 2;
//     while (t > 0 ) {
//         --t;
//         std::string message;
//         std::cout << "Type a message: ";
//         std::getline(std::cin, message);

//         if (message.empty())
//             continue;

//         send(sock, message.c_str(), message.length(), 0);
//         printf("Message sent: %s\n", message.c_str());
//     }

//     close(sock);
// }