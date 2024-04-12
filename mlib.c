// Ubuntu linux 64 bit

#define SYSEXIT 60

#include "include/mlib.h"
#include "include/main.h"
#include "include/mio.h"

void sysExit(int errcode) {
    asm volatile
        (
            "syscall"
            :
            :"a"(SYSEXIT), "D"(errcode)
        );
}

void processorError(int code) {
    code
        ? print("\nProgram finished with error!\n")
        : print("\nProgram finished successfully!\n");
}

void _start() { 
    processorError(main());
    sysExit(12);
}