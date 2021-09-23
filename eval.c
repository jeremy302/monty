#include "monty.h"
#include <stdio.h>

/**
 * bop_stack - changes xixo mode to LIFO
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_stack(stack_t **stack, u32 lno)
{
	(void) stack, (void) lno;

	Pile->mode = LIFO;
}

/**
 * bop_queue - changes xixo mode to FIFO
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_queue(stack_t **stack, u32 lno)
{
	(void) stack, (void) lno;

	Pile->mode = FIFO;
}


/**
 * bop_push - pushes argument to top of the pile
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_push(stack_t **stack, u32 lno)
{
	(void) stack, (void) lno;

	if (Parser->arg_set)
		xixo_push(Parser->arg);
	else
		throw(ERR_BOP_PUSH, NULL);
}


/**
 * bop_pop - removes the top element
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_pop(stack_t **stack, u32 lno)
{
	(void) stack, (void) lno;

	if (Pile->top == NULL)
		throw(ERR_BOP_POP, NULL);
	xixo_pop();
}

/**
 * bop_nop - no operation
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_nop(stack_t **stack, u32 lno)
{
	(void) stack, (void) lno;
}
