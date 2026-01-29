#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For random number generation


// ------ Function declarations ----------
void create_random(int *tab, int max, int max_number); //This function creates a table of random numbers
void count_frequency(int *tab, int max, int *freq, int max_number); //This function counts the frequency of each number
void draw_histogram(int *freq, int max_val, int mode); //This function draws a histogram based on frequency counts


int main (int argc, char *argv[]){ //Main function

    if (argc < 4) {
        printf("Usage: %s <table_size> <max_number> <mode: 0=horizontal 1=vertical>\n", argv[0]);
        return 1;
    }
    int max = atoi(argv[1]); //Size of the table
    int max_number = atoi(argv[2]); //Maximum random number
    int mode = atoi(argv[3]); //Mode for histogram display

    int *table = (int *)malloc(max * sizeof(int)); //Dynamically allocated table of random numbers
    int *frequency = (int *)malloc(max_number * sizeof(int)); //Dynamically
    if(table == NULL || frequency == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    srand(time(NULL)); //Seeds the random number generator
    create_random(table, max, max_number); //Creates a table of random numbers
    count_frequency(table, max, frequency, max_number); //Counts the frequency of each number
    draw_histogram(frequency, max_number, mode); //Draws a histogram based on frequency counts

    free(table); //Frees the allocated memory for the table
    free(frequency); //Frees the allocated memory for the frequency table
    return 0; //Returns 0 to indicate successful completion
}

// ------ Function definitions ----------
void create_random(int *tab, int max, int max_number){ //This function creates a table of random numbers
    for(int i=0; i<max; i++){ //Loops through the table
        tab[i] = rand() % max_number; //Assigns a random number between 0 and max_number-1 to each element
    }
}
void count_frequency(int *tab, int max, int *freq, int max_number){ //This function counts the frequency of each number
    for(int i=0; i<max_number; i++){ //Initializes the frequency table to 0
        freq[i] = 0; //Sets each frequency count to 0
    }
    for(int i=0; i<max; i++){ //Loops through the random number table
        int number = tab[i]; //Gets the number at the current index
        if(number < max_number) { //safety check
            freq[number]++; //Increments the frequency count for that number
        }
    }
}
void draw_histogram(int *freq, int max_val, int mode){ //This function draws a histogram based on frequency counts
    if (mode == 0) {// Horizontal mode
        printf("\nHorizontal Histogram:\n");
        for(int i=0; i<max_val; i++){ //Loops through the frequency table
            printf("%2d: ", i); 
            for(int j=0; j<freq[i]; j++){ //Prints asterisks based on the frequency count
                printf("x");
            }
            printf("\n");
        }
    } 
    else {// Vertical mode
        printf("\nVertical Histogram:\n");
        int max_freq = 0;// Find the maximum frequency
        for (int i = 0; i < max_val; i++) { //loops through the frequency table
            if (freq[i] > max_freq) max_freq = freq[i];// Update max_freq if current frequency is greater
        }

        for (int h = max_freq; h > 0; h--) { // Draws each level of the histogram from top to bottom
            printf("%2d |", h);
            for (int i = 0; i < max_val; i++) { //loops through the frequency table
                if (freq[i] >= h) {// Prints 'x' if the frequency is at least h
                    printf(" x ");
                } else {// Prints spaces otherwise
                    printf("   ");
                }
            }
            printf("\n");
        }
        printf("    "); 
        for (int i = 0; i < max_val; i++) printf("---");// Prints the base line
        printf("\n    ");
        for (int i = 0; i < max_val; i++) printf("%2d ", i);// Prints the number labels
        printf("\n");
    }
}