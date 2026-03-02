#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: Name of the file
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w;
	char *buf;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	r = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	free(buf);
	close(fd);

	if (r == -1 || w != r)
		return (0);

	return (w);
}
