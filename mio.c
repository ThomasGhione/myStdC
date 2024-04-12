// Ubuntu linux 64 bit

#define SYSREAD 0
#define SYSWRITE 1

#include "include/mio.h"
#include "include/mlib.h"
#include "include/mstring.h"



void write(unsigned fd, const char* buf, size_t count) {
    asm volatile
        (
            "syscall"
            :
            :"a"(SYSWRITE), "D"(fd), "S"(buf), "d"(count)
        );
}

void read(unsigned fd, const char* buf, size_t count) {
    asm volatile
        (
            "syscall"
            :"=S"(buf)
            :"a"(SYSREAD), "D"(fd), "d"(count)
        );
}

void print(const char* buf) {
    write(1, buf, strlen(buf));
}

void scan(char* buf, size_t maxLen) {
    // int c = strlen(buf);
    int a = 0;

    read(0, buf, 1);
    // ++a;
    while (*buf != '\n' && a < maxLen)
        read(0, ++buf, 1);
    *buf = '\0'; // set the buffer to null terminator so we don't leak memory
}

void printf(const char *buf, ...) {

}



char* itoa(int value, char* result, int base) {
    // check that base case is valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    // apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void printNum(int num) {
    char *res;
    *res = itoa(num, res, 10);
    print(res);
}