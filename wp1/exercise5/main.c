#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For random number generation
#define MAX 100 //Defines the maximum number of the values in the table
#define MAXNUMBER 20 //Defines the maximum value of random numbers

// ------ Function declarations ----------
void create_random(int *tab); //This function creates a table of random numbers
void count_frequency(int *tab, int *freq); //This function counts the frequency of each number
void draw_histogram(int *freq); //This function draws a histogram based on frequency counts


int main (void){ //Main function

    int table[MAX]; //Table of random numbers
    int n; //Number of values in the table
    int frequency[MAXNUMBER]; //Table of frequency counts
    srand(time(NULL)); //Seeds the random number generator
    create_random(table); //Creates a table of random numbers
    count_frequency(table, frequency); //Counts the frequency of each number
    draw_histogram(frequency); //Draws a histogram based on frequency counts
    return 0; //Returns 0 to indicate successful completion
}

// ------ Function definitions ----------
void create_random(int *tab){ //This function creates a table of random numbers
    for(int i=0; i<MAX; i++){ //Loops through the table
        tab[i] = rand() % MAXNUMBER; //Assigns a random number between 0 and MAXNUMBER-1 to each element
    }
}
void count_frequency(int *tab, int *freq){ //This function counts the frequency of each number
    for(int i=0; i<MAXNUMBER; i++){ //Initializes the frequency table to 0
        freq[i] = 0; //Sets each frequency count to 0
    }
    for(int i=0; i<MAX; i++){ //Loops through the random number table
        int number = tab[i]; //Gets the number at the current index
        freq[number]++; //Increments the frequency count for that number
    }
}
void draw_histogram(int *freq){ //This function draws a histogram based on frequency counts
    for(int i=0; i<MAXNUMBER; i++){ //Loops through the frequency table
        printf("%2d: ", i); //Prints the number
        for(int j=0; j<freq[i]; j++){ //Prints asterisks based on the frequency count
            printf("x");
        }
        printf("\n");
    }
}