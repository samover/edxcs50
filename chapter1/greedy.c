/*
 * greedy.c
 * Implementation of a greedy algorithm
 *
 * created by samover
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

/*
 * Constant declarations
 */
int QUARTER = 25;
int DIME = 10;
int NICKEL = 5;

/*
 * Function declarations
 */
int getPennies(float change);
int getCoinsNum(int pennies);
bool isCorrect(float change);

/*
 * Main declarations
 */
int main(void)
{
    bool valid = false;
    float change;

    // User input should be >= 0;
    while(!valid)
    {
        printf("How much change are you owed? ");
        change = get_float();
        valid = isCorrect(change);
    }

    // convert the amount in dollars to pennies (rounded)
    int pennies = getPennies(change);

    // get the amount of coins needed to provide the customer with change
    int numCoins = getCoinsNum(pennies);

    // stdout
    printf("%d\n", numCoins);
}

bool isCorrect(float change)
{
    return change >= 0;
}

int getPennies(float change)
{
    return round(change * 100);
}

int getCoinsNum(int pennies)
{
    int numCoins = 0;

    numCoins += pennies / QUARTER;
    pennies = pennies % QUARTER;

    numCoins += pennies / DIME;
    pennies = pennies % DIME;

    numCoins += pennies / NICKEL;
    pennies = pennies % NICKEL;

    numCoins += pennies;

    return numCoins;
}
