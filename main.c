#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: An array containing the arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		error_out(1);
	open_file(argv[1]);

	free_nodes();
	return (0);
}
