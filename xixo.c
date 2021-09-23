#include "main.h"
#include <stdlib.h>

/**
 * xixo_data - gets the stored XIXOData
 *
 * Return: stored data
 */
XIXOData *xixo_data()
{
	static XIXOData data = { NULL, NULL, 0, LIFO };

	return (&data);
}

/**
 * xixo_push - adds a value to the top of the pile
 * @v: value
 *
 * Return: created node
 */
stack_t *xixo_push(i32 v)
{
	XIXOData *data = xixo_data();
	stack_t *node = malloc(sizeof(stack_t) * 1);

	if (node == NULL)
		throw(ERR_NO_MEM, NULL);
	++data->len;
	node->n = v;
	node->next = NULL;
	node->prev = NULL;
	if (data->top == NULL)
		data->top = node, data->bot = data->top;
	else if (data->mode == LIFO)
		data->top->next = node, node->prev = data->top,
			data->top = node;
	else
		data->bot->prev = node, node->next = data->bot,
			data->bot = node;
	return (node);
}

/**
 * xixo_pop - removes the top value from the pile
 *
 * Return: the removed value
 */
i32 xixo_pop(void)
{
	XIXOData *data = xixo_data();
	i32 v = data->top->n;
	void *tmp = data->top;

	if (data->top == data->bot)
		data->top = NULL, data->bot = NULL;
	else
		data->top = data->top->prev;
	--data->len;
	free(tmp);
	return (v);
}
