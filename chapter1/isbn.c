/*
 * isbn.c
 * An ISBN-10 validator
 *
 * created by samover
 */

#include <cs50.h>
#include <stdio.h>

int INIT_SUM = 0;
int ISBN_LENGTH = 10;

int getChecksum(long long isbn, int checksum, int pos)
{
    if (isbn == 0)
    {
        return checksum;
    }

    checksum += (isbn % 10) * pos;
    return getChecksum(isbn / 10, checksum, pos - 1);
}

bool isValid(long long isbn)
{
    int checksum = getChecksum(isbn, INIT_SUM, ISBN_LENGTH);
    return checksum % 11 == 0;
}

int main(void)
{
    printf("Please enter a isbn-10 to validate: ");
    long long isbn = get_long_long();

    printf("%s\n", (isValid(isbn) ? "YES" : "NO"));
}

