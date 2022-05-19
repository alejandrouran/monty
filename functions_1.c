#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @head: node pointer to head
 * @line: line number
 * Return: value
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_ *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}

/**
 * pop - removes the top element of the stack
 * @head: node pointer to head
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: cat't pop an empty stack\n" line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @head: node pointer to head
 * @line_number: line number 
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number);
{
	int tmp;

	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
