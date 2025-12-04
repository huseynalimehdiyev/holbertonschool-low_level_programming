#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
    long n = 612852475143;
    long i;

    /* Remove all factors of 2 first */
    while (n % 2 == 0)
        n /= 2;

    /* Start checking odd factors from 3 onwards */
    for (i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
            n /= i;
    }

    /* If remaining n is greater than 2, it's prime and largest factor */
    if (n > 2)
        printf("%ld\n", n);
    else
        printf("%ld\n", i - 2); /* Last factor checked in loop */

    return (0);
}

