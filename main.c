// Ubuntu linux 64 bit

#define SYSEXIT 60

#include "include/mlib.h"
#include "include/mio.h"
#include "include/main.h"
#include "include/mstring.h"

int main() {

    char in[10];
    scan(in, 10);
    print(in);

    return 0;
}

/*
void _start() {
    write(1, "Message printed using write function!", 37);
    print("\nMessage printed using print function!\n");
    char input[11];
    // read(0, input, 11);
    scan(input);
    print(input);
    print("\n");
    sysExit(12);
}
*/