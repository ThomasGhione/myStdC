// Ubuntu linux 64 bit

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define SYSEXIT 60

#include "include/mlib.h"
#include "include/main.h"
#include "include/mio.h"
#include "include/mlimits.h"

void exit(int status) {
    sysExit(status);
}

void abort() {
    exit(EXIT_FAILURE);
}

int abs(int x) {
    if (x == INT_MIN) {
        print("abs: integer overflow\n");
        abort();
    }
    return x < 0 ? -x : x;
}

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