# Week 1: Sockets & Networking Concepts

## Required Readings & Videos (Complete These First)

* **Beej’s Guide to Network Programming** (Sections 1–2, intro examples):
  [https://beej.us/guide/bgnet/html/](https://beej.us/guide/bgnet/html/)
* **Linux Man Pages:**

  * `socket(2)` – [https://man7.org/linux/man-pages/man2/socket.2.html](https://man7.org/linux/man-pages/man2/socket.2.html)
  * `ip(7)` – [https://man7.org/linux/man-pages/man7/ip.7.html](https://man7.org/linux/man-pages/man7/ip.7.html)
  * `tcp(7)` – [https://man7.org/linux/man-pages/man7/tcp.7.html](https://man7.org/linux/man-pages/man7/tcp.7.html)
* **Kurose & Ross:** Computer Networking: A Top-Down Approach (Ch. 1, optional)
* **YouTube:**

  * [Beej’s Sockets Intro](https://www.youtube.com/watch?v=6tNS--WetLI)
  * [LiveOverflow: TCP Handshake Explained Visually](https://www.youtube.com/watch?v=iW6m5HUr2Kk)

---

## Purpose

Build a foundational understanding of socket programming and networking essentials required for CNO (Computer Network Operations) and Reverse Engineering. By the end of this week, you should know exactly what a socket is, why it matters for offense/defense, and how the OS provides this abstraction in C.

---

## Core Concepts (Read, Watch, and Review)

### What is a Socket?

* An **OS abstraction** for network communication—think of it as a file descriptor for network I/O.
* Sockets let two programs (on the same or different machines) exchange data across a network, using the same `read`/`write` semantics as files.
* Key CNO context: nearly all real-world malware, CNO tools, and exploits use sockets for C2, persistence, exfil, and attacks.

### Networking Models: OSI & TCP/IP

* **OSI Model:** Conceptual 7-layer stack—Physical, Data Link, Network, Transport, Session, Presentation, Application.
* **TCP/IP Stack:** 4 practical layers—Link, Internet, Transport, Application. All real-world sockets operate at the Transport layer (TCP, UDP).
* **Transport Layer:** TCP (reliable, connection-oriented), UDP (unreliable, connectionless). Custom protocols and most CNO tools are built on these.

### Core Socket API in C

* **Common system calls:**

  * `socket()` – create a socket
  * `bind()` – bind address/port (server)
  * `listen()` – listen for incoming (TCP)
  * `accept()` – accept a connection
  * `connect()` – connect to server (client)
  * `send()`, `recv()` – send/receive data
  * `close()` – close the socket
* Sockets are managed via integer file descriptors.
* Sockets are bidirectional—any side can read or write (except UDP: one-off datagrams).

### Why Sockets Matter for CNO/RE

* **Exploitation:** Vulnerabilities in socket/network code (buffer overflows, info leaks, logic bugs) are common attack surfaces.
* **Reverse Engineering:** Malware, RATs, and CNO tools are often “just” programs that use sockets in clever/abnormal ways.
* **Recon:** Port scanning and socket enumeration are step one in real CNO.
* **Security:** Every line of code that touches a socket is an input vector for an attacker.

---

## Security Mindset & CNO Focus (Think Like an Attacker)

* **Attack Surfaces:**

  * How does your code handle unexpected data? What if the input is too long, or binary, or malicious?
  * What assumptions about remote endpoints (e.g., spoofed packets, man-in-the-middle)?
* **Operational Security:**

  * Can you detect open sockets (ports) on a target using basic tools?
  * Does your code leak information on error or crash? How would you find out?
* **Defensive Coding:**

  * Do you check all return values and handle errors? Is every buffer big enough? Are you validating every input?

---

## Example: Minimal TCP Client in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("socket"); exit(1); }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080); // Port 8080
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect"); exit(1);
    }
    char *msg = "Hello, server!";
    send(sockfd, msg, strlen(msg), 0);
    close(sockfd);
    return 0;
}
```

---

## Expected Outcome & Deliverables

* **Explanation:** In your own words, explain what a socket is, how/why it’s used in CNO/RE, and what the main socket API calls do in C.
* **Diagram:** Draw a basic client-server handshake (plain English or ASCII art).
* **Security Reflection:** Identify at least one attack surface for your code (e.g., what if server response is oversized, or the address is invalid?).
* **Prepare:** For Week 2, plan to implement and test a simple echo server/client.
