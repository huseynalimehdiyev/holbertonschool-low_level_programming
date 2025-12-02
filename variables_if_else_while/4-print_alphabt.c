#include <stdio.h>
/**
 * main - prints the alphabet in lowercase, except q and e,
 *        followed by a new line
 *
 * Return: Always 0 (Success)
 */
 
int main() 
{
    char c;
    
    for (c='a';c<='z';c++)
        if (c!='e' && c!='q')
            putchar(c);
        putchar('\n');
    return (0);
}
