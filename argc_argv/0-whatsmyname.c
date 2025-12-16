#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: argument count (unused)
 * @argv: argument vector (array of arguments)
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
    (void)argc;            /* argc istifadə olunmur, xətanı önləmək üçün */
    printf("%s\n", argv[0]); /* argv[0] proqramın adı */
    return (0);
}
