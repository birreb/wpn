#include <stdio.h>                                              //
                                        
int main (int argc, char **argv) {                              // We use ** because it points to an array of strings
    printf("Hello World! – I'm %s!\n", argv[1]);                //
    return 0;                                                   //
}