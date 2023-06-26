#include <stdio.h>
#include "monty.h"

/**
 * main - main function
 * @argc: argument counts
 * @argv: arguments vector
 * Result: message indicating success or failure.
 */

int main(int argc, char **argv)
{
	ssize_t getline(char **lineptr, size_t *n, FILE *stream);
	FILE *file;
	char *buff = NULL;
	char *Str;
	size_t buff_size = 0;
	ssize_t read_line;
	unsigned int line_num = 1;
	stack_t *stk = NULL;

	values.cmd = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_line = getline(&buff, &buff_size, file);
	while (read_line != -1)
	{
		if (*buff != '\n')
		{
			Str = strtok(buff, "\n");
			tokenize_str(Str, &stk, line_num);
		}
		line_num++;
	}
	fclose(file);
	free(buff);
	if (stk != NULL)
		freeStk(&stk, line_num);
	return (EXIT_SUCCESS);
}

/**
 * freeStk - frees a stack
 * @stk: pointer to the top of the stack
 * @line_num: line number
 * Return: a structure containing the freed stack and line number
 */
FreeResult freeStk(stack_t **stk, unsigned int line_num)
{
	FreeResult result;
	stack_t *current = *stk;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stk = NULL;
	result.stk = NULL;
	result.line_num = line_num;

	return (result);
}

/**
 *tokenize_str - function to tokenize strings and commands
 * @string: string to be tokenized
 * @stk: pointer to the stack
 * @line_num: line numbers
 */
void tokenize_str(char *string, stack_t **stk, unsigned int line_num)
{
	char *token;
	char *token_cart;

	token = strtok(string, " ");
	if (strspn(token, " \n#") == strlen(token))
		return;
	if (strcmp(token, "push") == 0)
	{
		token_cart = token;
		token = strtok(NULL, " ");
		if (!isTokenNumeric(token))
		{
			printf("L%d: usage: push integer\n", line_num);
			freeStk(stk, line_num);
			exit(EXIT_FAILURE);
		}
		values.numb = atoi(token);
		_exec(token_cart, stk, line_num);
	}
	else
		_exec(token, stk, line_num);
}


/**
 * isTokenNumeric - check if string is numeric.
 * @token: string to be checked.
 * Return: 1 if true, 0 if false
 */
int isTokenNumeric(char *token)
{
	if (token == NULL)
		return (0);

	if (*token == '-')
		token++;

	for (; *token != '\0'; token++)
	{
		if (!isdigit(*token))
			return (0);
	}
	return (1);
}
