#include "monty.h"
#include <stdio.h>


/**
 * bop_div - divides the 2nd element by the top
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_div(stack_t **stack, u32 lno)
{
	i32 v;

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_DIV, NULL);
	else if (Pile->top->n == 0)
		throw(ERR_BOP_DIVZ, NULL);
	v = xixo_pop();
	Pile->top->n = Pile->top->n / v;
}

/**
 * bop_mod - finds the remainder of the 2nd element divided by the top
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_mod(stack_t **stack, u32 lno)
{
	i32 v;

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_MOD, NULL);
	else if (Pile->top->n == 0)
		throw(ERR_BOP_MODZ, NULL);
	v = xixo_pop();
	Pile->top->n = Pile->top->n % v;
}
