#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    char binary[65];

    if (argc > 1) {
        strcpy(binary, argv[1]);
    } else {
        scanf("%s", binary);
    }

    long num = strtol(binary, NULL, 2);

    // Determine hex digits needed (4 bits per hex digit)
    int bits = strlen(binary);
    int hex_digits = (bits + 3) / 4;  // Round up

    printf("%0*lX\n", hex_digits, num);
    return 0;

}