// Ubuntu linux 64 bit

#define SYSREAD 0
#define SYSWRITE 1

#include "include/mio.h"
#include "include/mlib.h"
#include "include/mstring.h"
#include "include/mlimits.h"


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
    write(stdout, buf, strlen(buf));
}

void scan(char *buf, size_t max) {
    read(0, buf, 1);
    int a = 0;
    while (*buf != '\n' && a < max) {
        ++a;
        read(stdin, ++buf, 1);
    }
    *buf = '\0';
}

void puts(const char* buf) {
    print(buf);
}

void gets(char* buf) {
    scan(buf, UINT_MAX);
}

void scanf(const char* format, ...) {
    
    char *ptr = format;
    ptr += sizeof(*format) / sizeof(char);

    if (*format != '%') {
        print("scanf: invalid format\n");
        //processError(1);
        return; // TODO remove this
    }

    ++format;

    switch (*format) {
        case 's':
            read(stdin, *ptr, 1);
            while (*ptr != '\n') {
                ++ptr;
                read(stdin, *ptr, 1);
            }
            *ptr = '\0';
            break;
        case 'd':
            int i = *ptr;
            char *res = itoa(i, res, 10);
            print(res);
            break;
        default:
            print("scanf: not supported or wrong type :(\n");
            //processError(1);
            return; // TODO remove this
    }

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