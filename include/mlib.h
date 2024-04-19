// Ubuntu linux 64 bit

#ifndef __MLIB__
#define __MLIB__

#include "mstring.h"

typedef unsigned size_t;

void exit(int status);
void abort();

int abs(int x);

void sysExit(int errcode);
void processorError(int code);

#endif // __MLIB__