# Socket Programming in C (CNO Track) — 10-Week Self-Study Syllabus

Welcome! This repository contains my self-study journey to master CNO-relevant socket/network programming using C, with labs, code, and reflective write-ups.

---

## 📚 Course Overview

**Goal:**  
Build foundational and applied skills in C network/socket programming, focusing on knowledge and hands-on experience essential for Cyber Network Operations (CNO):  
- Writing robust, secure C networking code  
- Understanding/implementing TCP, UDP, custom protocols  
- Debugging, analyzing, and mitigating vulnerabilities  
- Documenting progress and building a professional portfolio

**What You’ll Produce:**  
- 10 completed labs (code, write-ups, protocol docs)  
- A capstone project demonstrating full-stack network development and CNO thinking  
- Weekly README logs to track growth and learning

---

## 🗂️ Table of Contents

- [Course Overview](#course-overview)
- [Weekly Schedule](#weekly-schedule)
- [Resources](#resources)
- [Labs](#labs)
- [Progress Log](#progress-log)

---

## 🗓️ Weekly Schedule

| Week | Topic                                             | Assignment Folder     |
|------|---------------------------------------------------|----------------------|
| 1    | Sockets & Networking Concepts                     | [LAB1](./LAB1)       |
| 2    | TCP Echo Server & Client                          | [LAB2](./LAB2)       |
| 3    | Error Handling, Logging, & Debugging              | [LAB3](./LAB3)       |
| 4    | UDP Sockets & Datagram Communication              | [LAB4](./LAB4)       |
| 5    | Handling Multiple Clients (select(), Threads)     | [LAB5](./LAB5)       |
| 6    | Protocol Design & Implementation                  | [LAB6](./LAB6)       |
| 7    | Security & Exploitation—Finding and Fixing Bugs   | [LAB7](./LAB7)       |
| 8    | Network Traffic Analysis (Wireshark/tcpdump)      | [LAB8](./LAB8)       |
| 9    | Advanced Sockets—Non-blocking, Socket Options     | [LAB9](./LAB9)       |
| 10   | Capstone Project—Full-Featured Network Tool       | [CAPSTONE](./CAPSTONE) |

---

## 📖 Resources

- [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/)
- [SEED Labs: Networking & Buffer Overflow](https://seedsecuritylabs.org/Labs_16.04/Networking/)
- [GeeksforGeeks: Socket Programming in C/C++](https://www.geeksforgeeks.org/socket-programming-cc/)
- [Wireshark User Guide](https://www.wireshark.org/docs/wsug_html_chunked/)
- [Linux Programming Interface](https://man7.org/tlpi/)
- [Corelan Buffer Overflow Series](https://www.corelan.be/index.php/articles/)
- [POSIX Threads Programming (LLNL)](https://computing.llnl.gov/tutorials/pthreads/)
- [RFC 5321 (SMTP Protocol Example)](https://datatracker.ietf.org/doc/html/rfc5321)
- [tcpdump cheat sheet](https://danielmiessler.com/study/tcpdump/)

---

## 🧑‍💻 Labs

Each lab folder will include:
- `labX.md`: Assignment & instructions
- `labX.c`: Source code (or .h, .txt as needed)
- `labX_writeup.md`: What you built, what broke, what you learned

---

## 📆 Week-by-Week Breakdown

---

### **Week 1: Sockets & Networking Concepts**

- **Topic:** What is a socket? Networking fundamentals for CNO.
- **Learning Objectives:**
  - Explain TCP/UDP, OSI layers, and the role of sockets.
  - Identify and describe basic socket API calls in C.
- **Key Resources:**
  - Beej’s Guide, Ch. 1–2
  - Linux man pages: `socket(2)`, `ip(7)`, `tcp(7)`
  - Kurose & Ross, Ch. 1 (optional)
- **Expected Outcome:**  
  - README summary: “what is a socket?” and its use in CNO.
  - List of essential socket syscalls in C.
- **Lab Assignment:**  
  - Write a short report identifying/explaining socket syscalls in C code.
  - Diagram or plain-English flow of a basic client-server handshake.

---

### **Week 2: TCP Echo Server & Client (Single Connection)**

- **Topic:** Implementing basic TCP communication in C.
- **Learning Objectives:**
  - Use `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, `recv()`.
  - Build and test a TCP client and server.
- **Key Resources:**
  - Beej’s Guide Ch. 5–6, example code
  - GeeksforGeeks: Socket Programming in C/C++
  - Relevant `man` pages
- **Expected Outcome:**
  - Working echo server and client (localhost).
  - README: How you compiled, ran, and tested the programs.
- **Lab Assignment:**
  - Implement a TCP echo server and matching client in C.
  - Demonstrate a successful round-trip message.

---

### **Week 3: Error Handling, Logging, & Debugging**

- **Topic:** Defensive coding and debugging in C.
- **Learning Objectives:**
  - Add robust error handling to all network code.
  - Use `gdb` and `strace` for debugging and analysis.
- **Key Resources:**
  - Beej’s Guide Ch. 6.6
  - [gdb quickstart](https://www.cs.cmu.edu/~gilpin/tutorial/)
  - [strace tutorial](https://strace.io/)
- **Expected Outcome:**
  - Echo server/client with error handling.
  - README: Example debug session (real or intentional bug).
- **Lab Assignment:**
  - Add error handling and logging.
  - Use `gdb` and `strace` to debug a crash or bug, document the process.

---

### **Week 4: UDP Sockets & Datagram Communication**

- **Topic:** Building connectionless servers and clients.
- **Learning Objectives:**
  - Implement UDP echo server and client.
  - Understand and explain differences between UDP and TCP.
- **Key Resources:**
  - Beej’s Guide Ch. 7
  - UDP vs TCP (Cloudflare)
- **Expected Outcome:**
  - UDP echo server/client (localhost).
  - README: Pros/cons of UDP vs TCP.
- **Lab Assignment:**
  - Build a UDP echo server and client in C.
  - Demonstrate sending, receiving, and (if possible) handling lost packets.

---

### **Week 5: Handling Multiple Clients (select(), Threads)**

- **Topic:** Servers for multiple simultaneous clients.
- **Learning Objectives:**
  - Use `select()` for multiplexed I/O.
  - Compare select(), threads, fork.
- **Key Resources:**
  - Beej’s Guide Ch. 6.8–6.10
  - select() tutorial (Beej)
  - LLNL POSIX Threads Tutorial
- **Expected Outcome:**
  - TCP server handling multiple clients (with `select()`).
  - README: Performance and scaling notes.
- **Lab Assignment:**
  - Refactor your server for multiple clients with `select()`.
  - Test with several clients; document findings.

---

### **Week 6: Protocol Design & Implementation**

- **Topic:** Building and documenting a custom protocol.
- **Learning Objectives:**
  - Create message formats, handshake logic, and simple commands.
  - Write clear protocol documentation/spec.
- **Key Resources:**
  - Beej’s Guide: Data Framing
  - RFC 5321 (for protocol documentation style)
- **Expected Outcome:**
  - Server/client pair with a custom text-based protocol.
  - Protocol spec/diagram.
- **Lab Assignment:**
  - Design/implement a text-based protocol (e.g., login/message/logout).
  - README: Protocol doc/spec and working demo.

---

### **Week 7: Security & Exploitation—Finding and Fixing Bugs**

- **Topic:** Security flaws in C network code—finding and fixing them.
- **Learning Objectives:**
  - Spot classic CNO-relevant bugs (buffer overflows, unchecked input).
  - Write an exploit PoC, patch the vulnerability.
- **Key Resources:**
  - SEED Labs: Buffer Overflow Lab
  - Corelan: Intro to Buffer Overflows
- **Expected Outcome:**
  - Vulnerability found and exploited (crash/info leak).
  - Patched/mitigated code and README explanation.
- **Lab Assignment:**
  - Analyze vulnerable code, write a simple exploit, then patch the bug.
  - Document before/after (screenshots and write-up).

---

### **Week 8: Network Traffic Analysis (Wireshark/tcpdump)**

- **Topic:** Packet capture, visualization, and analysis.
- **Learning Objectives:**
  - Capture traffic with Wireshark/tcpdump.
  - Identify flows, handshakes, and data in captured packets.
- **Key Resources:**
  - Wireshark User Guide
  - tcpdump cheat sheet
- **Expected Outcome:**
  - Annotated captures showing protocol operation.
  - README: Traffic flow and security observations.
- **Lab Assignment:**
  - Capture and analyze your protocol with Wireshark.
  - Annotate key traffic and discuss any security findings.

---

### **Week 9: Advanced Sockets—Non-blocking, Socket Options**

- **Topic:** Non-blocking servers, advanced tuning.
- **Learning Objectives:**
  - Use `fcntl()` for non-blocking sockets.
  - Set and explain socket options (`SO_REUSEADDR`, timeouts).
- **Key Resources:**
  - Beej’s Guide: Non-blocking I/O
  - TLPI Ch. 56, 61
- **Expected Outcome:**
  - Non-blocking, option-tuned server.
  - README: Improvements and issues discovered.
- **Lab Assignment:**
  - Refactor a previous server for non-blocking I/O and socket options.
  - README: What improved, what was harder, what broke.

---

### **Week 10: Capstone Project—Full-Featured Network Tool**

- **Topic:** Integrating everything: a robust, secure, multi-client C network application.
- **Learning Objectives:**
  - Build a full-featured network tool (e.g., chat, file transfer, CNO-focused).
  - Document, test, and review for security/maintainability.
- **Key Resources:**
  - All previous course resources
- **Expected Outcome:**
  - Feature-rich project with code, docs, protocol spec, and README.
  - Identified/fixed at least one vulnerability or design flaw.
- **Lab Assignment:**
  - Build a multi-client TCP tool with a custom protocol.
  - Include README: architecture diagram, protocol spec, test logs, and a mini “CTF”—document a vulnerability and how you fixed it.

---

## 📓 Progress Log

*I’ll update this section with links to my lab write-ups and weekly summaries as I go!*

- Week 1: [LAB1 Writeup](./LAB1/lab1_writeup.md)
- Week 2: [LAB2 Writeup](./LAB2/lab2_writeup.md)
- ...

---

