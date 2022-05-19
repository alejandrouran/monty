#include "monty.h"

/**
 * pall - prints the data of all nodes in head
 * @head: pointer to the head node pointer of head
 * @line_number: the line number
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * add - adds the top two elements of the stack
 * @head: node pointer to head
 * @line_number: line number
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	(*head)->next->n += (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}

/**
 * nop - doesn’t do anything
 * @head: node pointer to head
 * @line_number: line number
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
