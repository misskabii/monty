#include "monty.h"

/**
 * add_to_queue -function that adds a node to the queue
 * @new_node: pointer taht points to new node
 * @line_number: Interger representing line number of opcode
 */
void add_to_queue(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

/**
 * push- function that adds a node to stack
 * @new_node: pointer that points to new node
 * @line_number: Interger representing line number of the opcode
 */
void push(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	tmp->prev = NULL;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;

}

/**
 * pall - function that adds a node to the stack
 * @stack: Pointer that points pointing to top node of stack
 * @line_number: Interger representing line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - function that adds a node to the stack
 * @stack: Pointer that  points pointing to top node of stack
 * @line_number: Interger representing line number  of opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		others_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pint - function that prints the top node of stack
 * @stack: Pointer that points pointing to top node of stack
 * @line_number: Interger representing line number of opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		others_error(6, line_number);

	printf("%d\n", (*stack)->n);
}
