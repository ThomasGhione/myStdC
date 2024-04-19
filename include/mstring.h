// Ubuntu linux 64 bit

#ifndef _MSTRING_H
#define _MSTRING_H

#define NULL 0

#include "mlib.h"

typedef unsigned size_t;

size_t strlen(const char *buf);
int strcmp(const char *str1, const char *str2);
int *strcat(char *dest, const char *src);


#endif // _MSTRING_H