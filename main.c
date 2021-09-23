#include "main.h"

/**
 * main - monty byte code interpreter
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: 0 if script executes successfully, else 1
 */
int main(int argc, char *argv[])
{
	FILE *hd = NULL;

	if (argc != 2)
		throw(ERR_INV_USAGE, NULL);
	hd = fopen(argv[1], "r");
	if (hd == NULL)
		throw(ERR_SCRIPT_PERM, argv[1]);
	return (parse_file(hd));
}

/**
 * quit - cleans up then terminates calling process
 * @status: exit status
 *
 * Return: void
 */
void quit(u32 status)
{
	while (Pile->top != NULL)
		xixo_pop();
	exit(status);
}