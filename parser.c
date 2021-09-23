#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static instruction_t instruction_set[] = {
	{ "stack", bop_stack },
	{ "queue", bop_queue },

	{ "push", bop_push },
	{ "pop", bop_pop },
	{ "nop", bop_nop },
	{ "swap", bop_swap },
	{ "rotl", bop_rotl },
	{ "rotr", bop_rotr },

	{ "pall", bop_pall },
	{ "pint", bop_pint },
	{ "pchar", bop_pchar },
	{ "pstr", bop_pstr },

	{ "add", bop_add },
	{ "sub", bop_sub },
	{ "mul", bop_mul },
	{ "div", bop_div },
	{ "mod", bop_mod },

	{ NULL, NULL }
};

/**
 * is_num - checks if a string only has digits
 * @str: a string
 *
 * Return: 1 if `str` only has digits, else 0
 */
char is_num(char *str)
{
	if (str != NULL)
		for (; *str >= '0' && *str <= '9'; ++str)
			if (str[1] == '\0')
				return (1);
	return (0);
}

/**
 * parser_info - gets the parser info
 *
 * Return: data stored
 */
ParserInfo *parser_info()
{
	static ParserInfo info = { 0, 0, NULL, 0, 0, 0 };

	return (&info);
}

/**
 * parse_file - parses a monty script
 * @handle: script handle
 *
 * Return: exit status
 */
i32 parse_file(FILE *handle)
{
	ParserInfo *info = parser_info();
	i32 i = 0;
	char *bop, *arg_str;

	do {
		++info->lno, info->arg_set = 0, info->arg = 0;
		info->ln = NULL, info->lnlen = 0;
		getline(&info->ln, &info->lnlen, handle);
		if (info->ln == NULL)
			break;
		while (*info->ln == ' ' || *info->ln == '\t')
			++info->ln;
		if (*info->ln == '#' || *info->ln == '\n')
			continue;
		else if (*info->ln == '\0')
			break;
		bop = strtok(info->ln, " \n");
		arg_str = strtok(NULL, " \n");

		if (arg_str != NULL && is_num(arg_str))
			info->arg_set = 1, info->arg = atoi(arg_str);
		for (i = 0; instruction_set[i].opcode != NULL; ++i)
		{
			instruction_t inst = instruction_set[i];

			if (!strcmp(bop, inst.opcode))
			{
				if (inst.f != NULL)
					inst.f(NULL, 0);
				break;
			}
		}
		if (instruction_set[i].opcode == NULL)
			throw(ERR_INV_BOP, bop);
	} while (info->ln != NULL);
	return (EXIT_SUCCESS);
}
