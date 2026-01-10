CC=cc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -g

all: byteorder

byteorder: byteorder.c
	$(CC) $(CFLAGS) -o byteorder byteorder.c
clean:
	rm -f byteorder

.PHONY: all clean

run: byteorder
	./byteorder
