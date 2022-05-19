#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @head: node pointer to head
 * @line_number: line number
 * Return: value
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
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
		fprintf(stderr, "L%d: cat't pop an empty stack\n", line_number);
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
void swap(stack_t **head, unsigned int line_number)
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

/**
 * push - pusehs  node to the top of stack
 * @head: pointer to the head node pointer of stack
 * @line_number: the line number
 * @arg: arguments
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line_number, char *arg)
{
	stack_t *node = NULL;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(arg);
	node->prev = NULL;
	node->next = *head;
	if (*head)
		(*head)->prev = node;

	(*head) = node;
}
