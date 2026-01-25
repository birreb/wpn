#include <stdio.h>                                          // for printf, getchar, putchar
#include <stdlib.h>                                         // for atoi

int main (int argc, char *argv[]) {                         // argc: argument count, argv: argument vector                

    if((argc) != 2){                                        // Check for correct number of arguments                
        printf("Error, you must provide a shift key.\n");   
        printf("Usage: %s [shift amount]\n", argv[0]);      
        return 1;                                           // Exit with error code     
    }

    int shift = atoi(argv[1]);                              // Convert argument to integer
    printf("Key accepted, shift amount: %d\n", shift);      
    int c;                                                  // Variable to hold each character 
    while ((c = getchar()) != EOF) {                        // Read characters until EOF
        if (c >= 'a' && c <= 'z') {                         // Check for lowercase letters
            putchar(((c - 'a' + shift) % 26) + 'a');        // Apply shift and wrap around
        } else if (c >= 'A' && c <= 'Z') {                  // Check for uppercase letters
            putchar(((c - 'A' + shift) % 26) + 'A');        // Apply shift and wrap around
        } else {                                            // Non-alphabetic characters
            putchar(c);                                     // Output unchanged
        }                                                                                
    }
    return 0;                                               // Exit successfully
}