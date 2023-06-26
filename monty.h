#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char cmd;
	int numb;
}dat_st;

extern dat_st values;
dat_st values;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
}stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
}instruction_t;

/**
 * struct FreeResult - structure holding freed stack and line number
 * @stk: pointer to the freed stack
 * @linenum: line number
 *
 * Description: Structure to hold information about a freed stack and its associated line number.
 */
typedef struct {
    stack_t *stk;
    unsigned int line_num;
}FreeResult;

FreeResult freeStk(stack_t **stk, unsigned int line_num);
void tokenize_str(char *string, stack_t **stk, unsigned int line_num);
int isTokenNumeric(char *token);
void _exec(char *token, stack_t **stk, unsigned int line_num);
void queue_ops(stack_t **stk, unsigned int line_num);
void _nop(stack_t **stk, unsigned int line_num);
void _push(stack_t **stk, unsigned int line_number);
void _pall(stack_t **stk, unsigned int line_num);
void _pop(stack_t **stk, unsigned int line_num);
void _pint(stack_t **stk, unsigned int line_num);
void _swap(stack_t **stk, unsigned int line_num);
void _add(stack_t **stk, unsigned int line_num);
void _sub(stack_t **stk, unsigned int line_num);
void _mul(stack_t **stk, unsigned int line_num);
void _div(stack_t **stk, unsigned int line_num);
void _mod(stack_t **stk, unsigned int line_num);
void _pchar(stack_t **stk, unsigned int line_num);
void _pstr(stack_t **stk, unsigned int line_num);

#endif
