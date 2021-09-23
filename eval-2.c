#include "monty.h"
#include <stdio.h>


/**
 * bop_pchar - prints the top element as an ascii character
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_pchar(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top;

	(void) stack, (void) lno;
	if (top == NULL)
		throw(ERR_BOP_PCHAR_EMP, NULL);
	else if (top->n < 0 || top->n > 127)
		throw(ERR_BOP_PCHAR_INV, NULL);
	printf("%c\n", top->n);
}

/**
 * bop_pstr - prints the topmost elements as a string
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_pstr(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top;

	(void) stack, (void) lno;
	for (; top != NULL && top->n != '\0'; top = top->prev)
		printf("%c", top->n);
	printf("\n");
}

/**
 * bop_add - adds the top 2 elements
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_add(stack_t **stack, u32 lno)
{
	i32 v;

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_ADD, NULL);
	v = xixo_pop();
	Pile->top->n = Pile->top->n + v;
}

/**
 * bop_sub - subtracts the top element from the second element
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_sub(stack_t **stack, u32 lno)
{
	i32 v = xixo_pop();

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_SUB, NULL);
	Pile->top->n = Pile->top->n - v;
}

/**
 * bop_mul - multiplies the top 2 elements
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_mul(stack_t **stack, u32 lno)
{
	i32 v = xixo_pop();

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_MUL, NULL);
	Pile->top->n = Pile->top->n * v;
}
