CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -Werror -O0 -g
LDFLAGS :=

all: echo_server

server: echo_server.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# client: client.c
# 	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# clean:
# 	rm -f server client

