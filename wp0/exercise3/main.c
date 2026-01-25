// (C) Filip Bystedt, Viggo Vahnström, group: 28 (2026)
// Work package 0
// Exercise 1
// Submission code: 28FBVVWP0 (provided by your TA-s)

#include <stdio.h>                                              // Package for input-output functions
#include <string.h>                                             // Package for input-output functions       

int main (int argc, char *argv[]) {                             // Main function with command-line arguments    

    if((argc) < 2){                                             // Check if no name is provided
        printf("Error: No name provided.\n");                   // Print error message                                                      
        printf("Use -h for help.\n");                           // Suggest help option
        return 1;                                               // Return error code
    }
    else if((argc) > 2){                                        // Check if too many arguments are provided
        printf("Error: Too many arguments provided.\n");        // Print error message      
        printf("Use -h for help.\n");                           // Suggest help option
        return 1;                                               // Return error code
    }
    else if(argc > 1 && strcmp(argv[1], "-h") == 0) {           // Check if help option is requested
        printf("Usage: ./program_name [your_name]\n");          // Print usage instructions
        return 1;                                               // Return error code
    }
    else {                                                      // If a name is provided
        printf("Hello World! – I'm %s!\n", argv[1]);            // Print greeting message with the provided name
        return 0;                                               // Return success code
    }
}