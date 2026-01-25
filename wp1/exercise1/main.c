#include <string.h>                                             // Package for string functions
#include <stdio.h>                                              // Package for input-output functions

int main (int argc, char *argv[]) { 
    
    char senteces[5][31];                                       // Declare an array that could hold 5 senteces of 30 characters + the 0 in the end
    int number;                                                 // Declare the int variable used (1 to 5)

    // Sentence part 
    for (int n = 0; n < 5; n++) {
        printf("Please enter sentence %d (max 30 characters): ", n + 1);
        
        while(1) {                                              // Loop until a valid sentence is entered
            scanf(" %[^\n]", senteces[n]);

            // Checking for length
            if (strlen(senteces[n]) > 30) {                     // We cant have 31 because strlen is reading characters not the null thing
                printf("Error: Sentence exceeds 30 characters. Please enter again: ");
            } 

            // Check for uniqueness
            else if (strcmp(senteces[n], senteces[n-1]) == 0 && n > 0) {
                printf("Error: Sentence must be unique. Please enter again: ");
            }

            // If valid
            else {
                break;                                           // exit the loop
            }
        }
    } 

    // Number part
    printf("Please enter a number between 1 and 5: ");
    
    // Loop until a valid number is entered
    while(1) {                                                
        scanf("%d", &number);                                    // Read the number, the & thing is needed to store the int at address
                              
        if (number < 1 || number > 5) {                          // Check if number is between 1 and 5          
            printf("Error: Number must be between 1 and 5. Please enter again: ");
        } 
        else {
            break;                                               // exit the loop
        }
    }
    printf("You selected sentence %d: %s\n", number, senteces[number - 1]); // Print the selected sentence
}    