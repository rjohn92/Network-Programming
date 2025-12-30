#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void) {
    puts("hello from the server");
    return 0;


    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    printf("Socket created with file descripter: %d\n", fd);
    close(fd);
    return 0;
}

