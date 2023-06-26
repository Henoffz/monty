#include "monty.h"

/**
 * _exec - execute functions having compared them with token received.
 * @token: command to be executed.
 * @stk: stack
 * @line_num: line number
 */
void _exec(char *token, stack_t **stk, unsigned int line_num)
{
	int i;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	if (strcmp(token, "stack") == 0)
	{
		values.cmd = 0;
		return;
	}

	if (strcmp(token, "queue") == 0)
	{
		values.cmd = 1;
		return;
	}

	if (values.cmd == 1 && strcmp(token, "push") == 0)
	{
		queue_ops(stk, line_num);
		return;
	}
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stk, line_num);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line_num, token);
	freeStk(stk, line_num);
	exit(EXIT_FAILURE);
}


/**
 *queue_ops - Enqueues an element to the back of the queue
 * @stk: Pointer to the stack (queue)
 * @line_num: Line number
 */
void queue_ops(stack_t **stk, unsigned int line_num)
{
	stack_t *new_node = NULL;
	stack_t *last_node = NULL;

	if (stk == NULL)
		exit(EXIT_FAILURE);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		freeStk(stk, line_num);
		exit(EXIT_FAILURE);
	}
	new_node->n = values.numb;
	new_node->next = NULL;

	if (*stk == NULL)
	{
		new_node->prev = NULL;
		*stk = new_node;
		return;
	}
	last_node = *stk;

	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;
	new_node->prev = last_node;
	values.numb = (*stk)->n;
}
/**
 * _nop - Does nothing
 * @stk: Pointer to the stack
 * @line_num: Line number
 */
void _nop(stack_t **stk, unsigned int line_num)
{
	(void)stk;
	(void)line_num;
}
