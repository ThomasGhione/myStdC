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

char* strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0; src[i] != '\0'; ++i)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

char* strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; ++i)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}