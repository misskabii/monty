#include "monty.h"
/**
 * new_node - This is a function that creates and populates a node
 * @n: number to go in the node
 * Return: on sucess a pointer to the node
 * Otherwise NULL
 */

stack_t *new_node(int n)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		error_out(4);
	nod->next = NULL;
	nod->prev = NULL;
	nod->n = n;
	return (nod);
}

/**
 * free_nodes - Thid is a function that frees nodes in the stack
 * return : void
 */
void free_nodes(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}
