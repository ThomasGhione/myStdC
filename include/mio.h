// Ubuntu linux 64 bit

#ifndef __MIO__
#define __MIO__

#include "mlib.h"

#define stdin 0
#define stdout 1
#define stderr 2

void write(unsigned fd, const char *buf, size_t count);
void read(unsigned fd, const char *buf, size_t count);

void print(const char *buf);
void printf(const char *buf, ...);
void scan(char *buf, size_t max);
void scanf(const char *format, ...);

void puts(const char *buf);
void gets(char *buf);

char* itoa(int value, char* result, int base);
void printNum(int num);

#endif // __MIO__