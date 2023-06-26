#include "monty.h"

/**
 * add - adds top two elements on stack
 * @stk: stack pointer
 * @line_num: line number
 */
void _add(stack_t **stk, unsigned int line_num)
{
	int first, second;
	int result = 0;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}

	first = (*stk)->n;
	_pop(stk, line_num);
	second = (*stk)->n;
	_pop(stk, line_num);

	result = first + second;
	_push(stk, result);
}

/**
 * sub - subtract one element from another from the 
 * top two stack.
 * @stk: stack pointer
 * @line_num: line number
 */

void _sub(stack_t **stk, unsigned int line_num)
{
	int first, second;
	int result = 0;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't subtract, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}

	first = (*stk)->n;
	_pop(stk, line_num);
	second = (*stk)->n;
	_pop(stk, line_num);

	result = second - first;
	_push(stk, result);
}

/**
 * _mul - multiply top two elements on stack
 * @stk: stack pointer
 * @line_num: line number
 */

void _mul(stack_t **stk, unsigned int line_num)
{
	int first, second;
	int result = 0;
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't multiply, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}

	first = (*stk)->n;
	_pop(stk, line_num);
	second = (*stk)->n;
	_pop(stk, line_num);

	result = second * first;
	_push(stk, result);
}

/**
 * _div - divides top two elements on stack
 * @stk: stack pointer
 * @line_num: line number
 */

void _div(stack_t **stk, unsigned int line_num)
{
	int first, second;
	int result = 0;
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't divide, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	first = (*stk)->n;
	_pop(stk, line_num);
       	if (first == 0)
	{
		printf("L%d: division by zero\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	second = (*stk)->n;
	_pop(stk, line_num);
	result = second / first;
	_push(stk, result);
}

/**
 * _mod - calculate the modulus of second and first top.
 * element on stack
 * @stack: stack pointer
 * @line_number: number of line opcode occurs on
 */

void _mod(stack_t **stk, unsigned int line_num)
{
	int first, second;
	int result = 0;
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	first = (*stk)->n;
	_pop(stk, line_num);

	if (first == 0)
	{
		printf("L%d: division by zero\n", line_num);
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	second = (*stk)->n;
	_pop(stk, line_num);
	result = second % first;
	_push(stk, result);
}
