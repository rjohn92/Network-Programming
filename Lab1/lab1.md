# LAB 1 — Sockets & Networking Concepts

## Objective

Understand and explain the basics of networking and sockets, focusing on the concepts and system calls foundational to all network programming in C.  
You’ll learn to identify the critical parts of a simple network program, recognize the socket API, and describe the data flow of a basic client/server.

---

## What You’ll Learn

- The meaning and use of "sockets" in modern computing
- The difference between TCP and UDP
- The C system calls required for socket programming
- How a basic network connection is made and managed

---

## Key Readings

- [Beej’s Guide to Network Programming, Ch. 1–2](https://beej.us/guide/bgnet/)
- [Linux man page: `socket(2)`](https://man7.org/linux/man-pages/man2/socket.2.html)
- [Linux man page: `ip(7)`](https://man7.org/linux/man-pages/man7/ip.7.html)
- [Linux man page: `tcp(7)`](https://man7.org/linux/man-pages/man7/tcp.7.html)

(Optional, for more context:  
- Kurose & Ross, Ch. 1)

---

## Lab Instructions

### 1. **Short Research/Writeup**
- In `lab1_writeup.md`, answer in your own words:
    1. What is a socket, and why is it fundamental to network communication?
    2. Briefly compare TCP vs UDP. When might you choose one over the other in offensive/defensive cyber work?
    3. What are the steps (and system calls) for a basic TCP server and a basic TCP client in C?  
       (List each syscall and its role in the connection process—can be in bullet points or a simple diagram.)

---

### 2. **Code Walkthrough**
- Find (or use the simple code below) a minimal C TCP server *and* client example.
- In `lab1.md`:
    - Paste the code (or link to it) with line numbers.
    - For each function call related to sockets (`socket()`, `bind()`, `listen()`, `accept()`, `connect()`, etc.), write a one-sentence explanation of what it does.
    - If you’re using a code sample from Beej or elsewhere, reference your source.

**Sample Minimal TCP Server:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(12345);

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); // bind address/port
    listen(sockfd, 1); // listen for connections
    int clientfd = accept(sockfd, NULL, NULL); // accept a connection
    char buffer[128] = {0};
    recv(clientfd, buffer, 128, 0); // receive data
    send(clientfd, buffer, strlen(buffer), 0); // send data back
    close(clientfd);
    close(sockfd);
    return 0;
}
