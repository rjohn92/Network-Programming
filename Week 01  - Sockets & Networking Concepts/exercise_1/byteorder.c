#include <stdio.h>
#include <stdint.h>

static void dump_bytes(const void *ptr, size_t size) {
    const unsigned char *byte_ptr = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", byte_ptr[i]);
    }
}

static int is_little_endian(void) {
    uint32_t num = 1;

    const unsigned char *p = (const unsigned char *)&num; 
    
    // If the first byte is 1, then the system is little-endian
    if (p[0] == 1) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {

    // Check endianness
    if (is_little_endian()) {
        printf("My system is little-endian.");
    } else {
        printf("My system is big-endian.");
    }

    puts("");

    printf("Dumping bytes...\n");
    uint8_t test[] = {0x00, 0x11, 0xAA, 0xFF};
    dump_bytes(test, sizeof(test));
    puts("");
    return 0;
}