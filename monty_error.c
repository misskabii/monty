#include "monty.h"
/**
 * error_out - A function that prints error messages
 * @error_code: error codes are the following
 */
void error_out(unsigned int error_code, ...)
{
	va_list a;
	char *opcode_error;
	unsigned int l_num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(a, char *));
			break;
		case 3:
			l_num = va_arg(a, unsigned int);
			opcode_error = va_arg(a, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", l_num, opcode_error);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * others_error - a function that handles errors
 * @error_code: error codes are the following
 */
void others_error(unsigned int error_code, ...)
{
	va_list a;
	char *opcode_error;
	unsigned int l_num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(a, unsigned int));
			break;
		case 7:
			fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(a, unsigned int));
			break;
		case 8:
			l_num = va_arg(a, unsigned int);
			opcode_error = va_arg(a, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", l_num, opcode_error);
			break;
		case 9:
			l_num = va_arg(a, unsigned int);
			opcode_error = va_arg(a, char *);
			fprintf(stderr, "L%u: can't div %s, stack too short \n",
					l_num, opcode_error);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
