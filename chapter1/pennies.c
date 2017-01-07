// Created by samover

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getDaysInMonthFromUser(void);
int getStartingPenniesFromUser(void);
long long getTotalPenniesForDaysInMonth(int numDay, int startingPennies, long long sum);
double convertPenniesToDollars(long long pennies);

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

int main()
{
    int days = getDaysInMonthFromUser();
    int numPennies = getStartingPenniesFromUser();
    long long totalPennies = getTotalPenniesForDaysInMonth(days, numPennies, 0);
    double dollars = convertPenniesToDollars(totalPennies);

    printf("$%.2f\n", dollars);
}

int getDaysInMonthFromUser() {
    int days = 0;

    while(days < 28 || days > 31) {
        printf("How many days are there in the month?");
        days = get_int();
    }

    return days;
}

int getStartingPenniesFromUser() {
    int numPennies = 0;

    while(numPennies <= 0) {
        printf("How many pennies do you receive on the first day?");
        numPennies = get_int();
    }

    return numPennies;
}

long long getTotalPenniesForDaysInMonth(int numDay, int startingPennies, long long sum) {
    numDay -= 1;

    if (numDay == 0)
    {
        return sum + startingPennies;
    }

    sum += pow(2, numDay) * startingPennies;

    return getTotalPenniesForDaysInMonth(numDay, startingPennies, sum);
}

double convertPenniesToDollars(long long pennies) {
    return pennies / 100.00;
}
