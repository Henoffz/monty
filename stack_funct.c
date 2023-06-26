#include "monty.h"

/**
 * _push - adds to stack's beginning.
 * @stk: top of stack
 * @line_num: line number.
 */
void _push(stack_t **stk, unsigned int line_num)
{
	stack_t *new_node;

	if (stk == NULL)
	{
		printf("L%d: unknown stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	new_node->n = values.numb;
	new_node->prev = NULL;
	new_node->next = *stk;

	if (*stk != NULL)
		(*stk)->prev = new_node;
	*stk = new_node;
}

/**
 * _pall - prints entire stack
 * @stk: top of stack
 * @line_num: line number
 */

void _pall(stack_t **stk, unsigned int line_num)
{
	stack_t *current;

	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: invalid stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	current = *stk;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pop - delete the top of stack
 * @stk: top of stack
 * @line_num: line number
 */

void _pop(stack_t **stk, unsigned int line_num)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stk)->next != NULL)
	{
		*stk = (*stk)->next;
		values.numb = (*stk)->n;
		free((*stk)->prev);
		(*stk)->prev = NULL;
	}
	else
	{
		free(*stk);
		*stk = NULL;
	}
}

/**
 * _pint - prints the data at the top of the stack
 * @stk: stack
 * @line_num: line number
 */

void _pint(stack_t **stk, unsigned int line_num)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stk)->n);
}

/**
 * _swap - swaps the  first two elements on top of stack
 * @stk: stack
 * @line_num: line number
 * Return: nothing
 */

void _swap(stack_t **stk, unsigned int line_num)
{
	int temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = temp;
}
