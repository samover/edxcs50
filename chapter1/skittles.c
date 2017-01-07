/*
 * skittles.c
 * Guessing game, using random generator
 *
 * created by samover
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Constant declarations
 */
int MIN_SKITTLES = 0;
int MAX_SKITTLES = 1023;

/*
 * Function declarations
 */
int play(int numSkittles);

/*
 * Main
 */
int main(void)
{
    srand(time(NULL));
    int numSkittles = rand() % (MAX_SKITTLES - 1);

    return play(numSkittles);
}

/*
 * play: gets and evaluates the user input
 */
int play(int skittles)
{
    int answer = -1;
    int numGuesses = 0;

    printf("Guess the number I am thinking of (0 - 1023): ");

    while (skittles != answer)
    {
        answer = get_int();
        numGuesses += 1;

        if (answer < MIN_SKITTLES)
        {
            printf("Haha, you funny! Try again, "
                    "and this time read the instructions: ");
        }
        else if (answer > MAX_SKITTLES)
        {
            printf("Unfortunately my jar in not thát big. Try againg: ");
        }
        else if (answer < skittles)
        {
            printf("More! more! more!. Try again: ");
        }
        else if (answer > skittles)
        {
            printf("I wish! Try a lower number: ");
        }
    }

    printf("Wow! Well done :-). It took you %d guesses.\n", numGuesses);
    printf("See you soon!\n\n");
    return 0;
}
