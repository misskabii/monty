#include "monty.h"

/**
 * swap - Swap element 1 for 2 of the stack
 * @stack: pointer that points the top node of the stack
 * @line_num: opcode line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add - function that adds top two elements of stack
 * @stack: Pointer that  points pointing to top node of the stack
 * @line_num: Interger rep the line number of opcode
 */
void add(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: top of the stack
 * @line_num: current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)*stack;
	(void)line_num;
}
