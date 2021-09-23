#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * throw_more - continuation of throw
 * @errno: error code
 * @str: extra info
 *
 * Return: void
 */
static void throw_more(ERRNO errno, char *str)
{
	FILE *hd = stderr;
	u32 lno = Parser->lno;

	(void) str;
	switch (errno)
	{
	case ERR_BOP_ADD:
		fprintf(hd, "L%d: can't add, stack too short", lno);
		break;
	case ERR_BOP_SUB:
		fprintf(hd, "L%d: can't sub, stack too short", lno);
		break;
	case ERR_BOP_MUL:
		fprintf(hd, "L%d: can't mul, stack too short", lno);
		break;
	case ERR_BOP_DIV:
		fprintf(hd, "L%d: can't div, stack too short", lno);
		break;
	case ERR_BOP_DIVZ:
		fprintf(hd, "L%d: division by zero", lno);
		break;
	case ERR_BOP_MOD:
		fprintf(hd, "L%d: can't mod, stack too short", lno);
		break;
	case ERR_BOP_MODZ:
		fprintf(hd, "L%d: division by zero", lno);
		break;
	case ERR_BOP_PCHAR_INV:
		fprintf(hd, "L%d: can't pchar, value out of range", lno);
		break;
	case ERR_BOP_PCHAR_EMP:
		fprintf(hd, "L%d: can't pchar, stack empty", lno);
		break;
	default:
		break;
	}
}
/**
 * throw - prints error message and terminates calling process
 * @errno: error type
 * @str: extra info
 *
 * Return: void
 */
void throw(ERRNO errno, char *str)
{
	FILE *hd = stderr;
	u32 lno = Parser->lno;

	switch (errno)
	{
	case ERR_INV_USAGE:
		fprintf(hd, "USAGE: monty file");
		break;
	case ERR_SCRIPT_PERM:
		fprintf(hd, "Error: Can't open file %s", str);
		break;

	case ERR_INV_BOP:
		fprintf(hd, "L%u: unknown instruction %s", lno, str);
		break;
	case ERR_NO_MEM:
		fprintf(hd, "Error: malloc failed");
		break;


	case ERR_BOP_PUSH:
		fprintf(hd, "L%u: usage: push integer", lno);
		break;
	case ERR_BOP_PINT:
		fprintf(hd, "L%d: can't pint, stack empty", lno);
		break;
	case ERR_BOP_POP:
		fprintf(hd, "L%d: can't pop an empty stack", lno);
		break;
	case ERR_BOP_SWAP:
		fprintf(hd, "L%d: can't swap, stack too short", lno);
		break;
	default:
		throw_more(errno, str);
	}
	fprintf(hd, "\n");
	quit(EXIT_FAILURE);
}
