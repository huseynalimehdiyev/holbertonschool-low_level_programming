#include "main.h"

/**
 * _prime_helper - checks if n is divisible by any number from i to n-1
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int _prime_helper(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (_prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (_prime_helper(n, 2));
}
