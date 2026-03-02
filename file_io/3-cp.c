#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - prints an error message to STDERR and exits
 * @code: exit code
 * @msg: message format
 * @arg: argument for message
 */
void print_error(int code, char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_file - closes a file descriptor and handles errors
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies contents from one file to another
 * @file_from: source file
 * @file_to: destination file
 */
void copy_file(char *file_from, char *file_to)
{
	int fd_from, fd_to, rd_bytes, wr_bytes;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_file(fd_from);
		print_error(99, "Error: Can't write to %s\n", file_to);
	}

	while ((rd_bytes = read(fd_from, buffer, 1024)) > 0)
	{
		wr_bytes = write(fd_to, buffer, rd_bytes);
		if (wr_bytes != rd_bytes || wr_bytes == -1)
		{
			close_file(fd_from);
			close_file(fd_to);
			print_error(99, "Error: Can't write to %s\n", file_to);
		}
	}

	if (rd_bytes == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		print_error(98, "Error: Can't read from file %s\n", file_from);
	}

	close_file(fd_from);
	close_file(fd_to);
}

/**
 * main - copies content of a file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
