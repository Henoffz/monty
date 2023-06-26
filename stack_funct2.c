#include "monty.h"

/**
 * _pchar - Print the character value of the top element of the stack
 * @stk: Pointer to the stack
 * @line_num: Line number
 */
void _pchar(stack_t **stk, unsigned int line_num)
{
	int val;

	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	val = (*stk)->n;

	if (val > 0 || val < 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", val);
}

/**
 * pstr - prints string
 * @stk: stack pointer
 * @line_num: declared void
 */

void _pstr(stack_t **stk, unsigned int line_num)
{
	stack_t *str;
	(void)line_num;

	str = *stk;
	while (str)
	{
		if (str->n > 127 || str->n <= 0)
		{
			break;
		}
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}
