#include "monty.h"
#include <stdio.h>

/**
 * bop_swap - swaps top 2 elements
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_swap(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top, *prev = top->prev;

	(void) stack, (void) lno;
	if (Pile->len < 2)
		throw(ERR_BOP_SWAP, NULL);
	prev->prev->next = top;
	top->prev = prev->prev;
	top->next = prev;
	prev->prev = top;
	prev->next = NULL;
	Pile->top = prev;
}

/**
 * bop_rotl - moves the top element to the bottom
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_rotl(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top, *bot = Pile->bot;

	(void) stack, (void) lno;
	if (top == NULL || top == bot)
		return;
	bot->prev = top;
	top->next = bot;
	Pile->top = top->prev;
	Pile->bot = top;
	top->prev->next = NULL;
	top->prev = NULL;
}

/**
 * bop_rotr - moves the bottom element to the top
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_rotr(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top, *bot = Pile->bot;

	(void) stack, (void) lno;
	if (top == NULL || top == bot)
		return;
	top->next = bot;
	Pile->bot = bot->next;
	Pile->top = bot;
	bot->next->prev = NULL;
	bot->prev = top;
	bot->next = NULL;
}

/**
 * bop_pall - prints all elements from top to bottom
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_pall(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top;

	(void) stack, (void) lno;
	for (; top != NULL; top = top->prev)
		printf("%d\n", top->n);
}

/**
 * bop_pint - prints the top element as an integer
 * @stack: pile
 * @lno: current line number
 *
 * Return: void
 */
void bop_pint(stack_t **stack, u32 lno)
{
	stack_t *top = Pile->top;

	(void) stack, (void) lno;
	if (top == NULL)
		throw(ERR_BOP_PINT, NULL);
	printf("%d\n", top->n);
}
