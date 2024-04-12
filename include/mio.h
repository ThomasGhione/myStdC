// Ubuntu linux 64 bit

#ifndef __MIO__
#define __MIO__

#include "mlib.h"

void write(unsigned fd, const char *buf, size_t count);
void print(const char *buf);
void printf(const char *buf, ...);

void read(unsigned fd, const char *buf, size_t count);
void scan(char *buf, size_t maxLen);



char* itoa(int value, char* result, int base);
void printNum(int num);

#endif // __MIO__