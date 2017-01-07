#include <stdio.h>
#include <cs50.h>

/*
 * Converts centigrades to fahrenheid
*/
int main(void)
{
    printf("Please enter a temperature in centigrades: ");
    float tempCelsius = GetFloat();
    float tempFahr = ((tempCelsius * 9) / 5) + 32;
    printf("F: %.1f\n", tempFahr);
}
