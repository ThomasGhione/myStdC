// Ubuntu linux 64 bit

#include "include/mlib.h"
#include "include/mstring.h"

size_t strlen(const char *buf) {
    size_t len = 0;
    while (*buf++ != '\0')
        ++len;
    return len;
}