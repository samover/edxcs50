// Created by samover

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getDays(void);
int getPennies(void);
long long getTotal(int numDay, int numPennies, long long sum);
double converter(long long pennies);

/*
 * If ever given the choice between $10,000,000 or a month’s worth of pennies,
 * whereby you receive a penny the first day, two pennies the second, four
 * pennies the third, and so forth… take the pennies.
 *
 * This app wil calculate how many dollars you will have at the end of the
 * month, given a number of days in the month and your starting amount of
 * pennies.
 *
 */

int main(void)
{
    int days = getDays();
    int numPennies = getPennies();
    long long totalPennies = getTotal(days, numPennies, 0);
    double dollars = converter(totalPennies);

    printf("$%.2f\n", dollars);
}

int getDays()
{
    int days = 0;

    while(days < 28 || days > 31)
    {
        printf("How many days are there in the month?");
        days = get_int();
    }

    return days;
}

int getPennies()
{
    int numPennies = 0;

    while(numPennies <= 0)
    {
        printf("How many pennies do you receive on the first day?");
        numPennies = get_int();
    }

    return numPennies;
}

long long getTotal(int numDay, int numPennies, long long sum)
{
    numDay -= 1;

    if (numDay == 0)
    {
        return sum + numPennies;
    }

    sum += pow(2, numDay) * numPennies;

    return getTotal(numDay, numPennies, sum);
}

double converter(long long pennies)
{
    return pennies / 100.00;
}
