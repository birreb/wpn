#include <string.h> // Package for string functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Neeeded to seed the randomness

int main()
{
    int number;
    srand(time(NULL)); // From W3: Call srand() only once, at the start of main. Do not call it again inside a loop.
    int random = rand() % 101; // Used some from https://www.w3schools.com/c/c_random_numbers.php

    while (1)
    {   
        printf("Guess a number between 0 and 100: ");
        if (scanf("%d", &number) != 1)
        {
            printf("Invalid input, enter an integer.\n");
            while (getchar() != '\n')
            continue;
        }

        if (number > random)
        {
            printf("Too high, try again!\n");
        }
        else if (number < random)
        {
            printf("Too low, try again!\n");
        }
        else if (number == random)
        {
            printf("Congratulations! You guessed the correct number: %d\n", random);
            break;
        }
    }

    printf("Wanna play again? (y/n): ");
    char answer[3];
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0)
    {
        main(); 
    }
    else
    {
        printf("Bye\n");
    }
}