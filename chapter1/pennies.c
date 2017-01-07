// Created by samover

#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long getTotalPenniesForDaysInMonth(int numDay, int startingPennies, long long sum);

int main()
{
    int days = 0;
    int numPennies = 0;

    while(days < 28 || days > 31) {
        printf("How many days are there in the month?");
        days = get_int();
    }

    while(numPennies <= 0) {
        printf("How many pennies do you receive on the first day?");
        numPennies = get_int();
    }

    long long totalPennies = getTotalPenniesForDaysInMonth(days, numPennies, 0);
    double dollars = totalPennies / 100.00;

    printf("$%.2f\n", dollars);
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
