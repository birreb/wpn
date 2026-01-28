#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    long number = 0;
    char *endptr;                                    // Pointer to track where conversion stopped

    if (argc > 1) {
        number = strtol(argv[1], &endptr, 10);       // Convert string to long based on last number
        if (*endptr != '\0') {                       // Check if entire string was converted
            printf("Invalid input: %s\n", argv[1]);
            return 1;                                // Return error code for invalid input
        }
    }
    else {
        scanf("Provide a number: %ld", &number);     // Read number from standard input
    }

    int bit_width = define_bit_width(number);
    
    for (int i = bit_width - 1; i >= 0; i--) {      // So in the exercise it says 8 bit, so we need to shift to convert eg: 12 -> 00001100 by logic:
        printf("%d", (number >> i) & 1);            // 12 -> (8<=12 = YES) + (4<=4 = YES) + (2<=0 = NO) + (1<=0 = NO) -> 00001100, the 0 before is 16,32,64,128
    }                                               // We use MSB first (most significant bit = 128 for 8 bit) to LSB last (least significant bit = 1)
    return 0;
}

int define_bit_width(long number) {                  // Function to determine bit width
    if (number <= 255)                                
        return 8;                                    // 8 bits for numbers up to 255 (char)
    else if (number <= 65535) 
        return 16;                                   // 16 bits for numbers up to 65535 (short)
    else if (number <= 4294967295L) 
        return 32;                                   // 32 bits for numbers up to 4294967295 (int)
    else 
        return 64;                                   // 64 bits for larger numbers (long)
}