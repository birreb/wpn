#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    char binary[65];                               // Max 64 bit + null terminator

    if (argc > 1) {
        strcpy(binary, argv[1]);                   // Take the argument as binary string
    } else {
        scanf("%s", binary);                       // Reads from the pipe stdout as string input
    }

    long num = strtol(binary, NULL, 2);            // Convert binary string to long integer

    int bits = strlen(binary);                     // Get the number of bits, like 00001111 = 8 bits
    int hex_digits = (bits + 3) / 4;               // Eg. 00001111 = 8 bits = 11+3 /4 = 2 hex digits = 0F (F kommer från 8+4+2+1 = 15 decimalt)

    printf("%0*lX\n", hex_digits, num);            // l, because print needs to know how big the number is (long)

    
    return 0;

}