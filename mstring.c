// Ubuntu linux 64 bit

#include "include/mlib.h"
#include "include/mstring.h"

size_t strlen(const char *buf) {
    size_t len = 0;
    while (*buf++ != '\0')
        ++len;
    return len;
}

int strcmp(const char *str1, const char *str2) {
    return strlen(str1) - strlen(str2);
}

int* strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr != '\0')
        ++ptr;
    while (*src != '\0') {
        *ptr = *src;
        ++ptr;
        ++src;
    }
    *ptr = '\0';
    return dest;
}