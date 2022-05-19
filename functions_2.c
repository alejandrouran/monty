#include "monty.h"

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * #liine: the line number
 * 
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line)
{
    stack_t *tmp;
    (void)line;

    tmp = *stack;
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}