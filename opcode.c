#include "monty.h"

/**
 * search_func - Finds the function to be executed
 * @opcode: operation code, It could be push or pall
 * @cmd: possible value for the operation
 * @l_num: the line number for the opcode
 * @format: specifier:
 * If the value is 0 = Stack
 * If the value is 1 = Queue
 */
void search_func(char *opcode, char *cmd, int l_num, int format)
{
	int p;
	int err;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{NULL, NULL}
	};
	/*
	 *when the first character is a #... ignore the
	 *error and continue to execute
	 */
	if (opcode[0] == '#')
		return;

	/*Search list for the function to be used*/
	for (err = 1, p = 0; functions[p].opcode != NULL; p++)
	{
		/*Correct opcode and didn't find any error*/
		if (strcmp(opcode, functions[p].opcode) == 0)
		{
			call_fun(functions[p].f, opcode, cmd, l_num, format);
			err = 0;
		}
	}
	if (err == 1)
	{
		error_out(3, l_num, opcode);
	}
}

/**
 * call_fun - function that calls the required function
 * @f: Pointer to function that is about to be called
 * @op: string representing opcode
 * @cmd: string representing numeric value
 * @l_num: line numeber for instruction
 * @format: Format specifier. If 0 Nodes will be entered as a stack
 * if 1 nodes will be entered as a queue
 */
void call_fun(op_func f, char *op, char *cmd, int l_num, int format)
{
	stack_t *node;
	int err;
	int j;

	err = 1;
	if (strcmp(op, "push") == 0)
	{
		/*Checks if number is negative and moves the val ptr*/
		if (cmd != NULL && cmd[0] == '-')
		{
			cmd = cmd + 1;
			err = -1;
		}
		/*val is not a digit is the return value is 0*/
		if (cmd == NULL)
		{
			error_out(5, l_num);
		}


		for (j = 0; cmd[j] != '\0'; j++)
		{
			if (isdigit(cmd[j]) == 0)
			{
				error_out(5, l_num);
			}

		}

		/*Create new node*/
		node = new_node(atoi(cmd) * err);
		if (format == 0)
			f(&node, l_num);
		if (format == 1)
			add_to_queue(&node, l_num);
	}
	else
		f(&head, l_num);
}
