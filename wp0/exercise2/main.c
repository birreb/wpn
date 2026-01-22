#include <stdio.h>                                              // Package for input-output functions
                                        
int main (int argc, char *argv[]) {                              // We use ** because it points to an array of strings
    printf("Hello World! – I'm %s!\n", argv[1]);                // Print a message with the name from command line arguments
    return 0;                                                   // Return 0 to indicate successful execution
}