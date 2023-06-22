#include "monty.h"
/**
 * open_file - a function that opens a file
 * @file_name: String with the name of the file
 */
void open_file(char *file_name)
{
	int file_c;
	FILE *fd;

	if (file_name == NULL)
		error_out(2, file_name);

	file_c = access(file_name, R_OK);
	if (file_c == -1)
		error_out(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_out(2, file_name);

	read_file(fd);

	fclose(fd);
}
/**
 * read_file - a function that reads the content of a file line by line
 * @fd: points to a file descriptor of an open file
 */
void read_file(FILE *fd)
{
	int num_line;
	int format = 0;
	char *lineprt = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_out(2, "file_name");

	for (num_line = 1; getline(&lineprt, &n, fd) != EOF; num_line++)
	{
		format = interpret_line(lineprt, num_line, format);
	}
	free(lineprt);
}
/**
 * interpret_line - a function that interpret each line by separating
 * @string: string on the line to be read
 * @line_number: line number for the opcode
 * @format: Format specifier
 * If the value is 0 --> Stack
 * If the value is 1 --> Queue
 * Return: Returns 0 if the opcode is stack
 * 1 if queue
 */
int interpret_line(char *string, int line_number, int format)
{
	char *opcode;
	char *cmd;
	const char *del;

	del = "\n ";

	if (string == NULL)
		error_out(4);

	opcode = strtok(string, del);

	if (opcode == NULL)
		return (format);

	cmd = strtok(NULL, del);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	search_func(opcode, cmd, line_number, format);
	return (format);
}
