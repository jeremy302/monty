#ifndef MAIN_H
#define MAIN_H
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

typedef int8_t i8, int8, byte;
typedef uint8_t u8, uint8, ubyte;
typedef int16_t i16, int16;
typedef uint16_t u16, uint16;
typedef int32_t i32, int32;
typedef uint32_t u32, uint32;
typedef int64_t i64, int64;
typedef uint64_t u64, uint64;

/**
 * enum ERRNO - Error codes
 * @ERR_INV_USAGE: usage error
 * @ERR_SCRIPT_PERM: script reading error
 * @ERR_INV_BOP: invalid opcode
 * @ERR_NO_MEM: failed memeory allocation
 * @ERR_BOP_PUSH: invalid push
 * @ERR_BOP_PINT: invalid pint
 * @ERR_BOP_POP: invalid pop
 * @ERR_BOP_SWAP: invalid swap
 * @ERR_BOP_ADD: invalid add
 * @ERR_BOP_SUB: invalid sub
 * @ERR_BOP_MUL: invalid mul
 * @ERR_BOP_DIV: invalid div
 * @ERR_BOP_DIVZ: division by zero
 * @ERR_BOP_MOD: invalid mod
 * @ERR_BOP_MODZ: division by zero
 * @ERR_BOP_PCHAR_INV: invalid pchar
 * @ERR_BOP_PCHAR_EMP: empty pchar
 */
typedef enum ERRNO
{
	ERR_INV_USAGE,
	ERR_SCRIPT_PERM,

	ERR_INV_BOP,
	ERR_NO_MEM,

	ERR_BOP_PUSH,
	ERR_BOP_PINT,
	ERR_BOP_POP,
	ERR_BOP_SWAP,
	ERR_BOP_ADD,
	ERR_BOP_SUB,
	ERR_BOP_MUL,
	ERR_BOP_DIV,
	ERR_BOP_DIVZ,
	ERR_BOP_MOD,
	ERR_BOP_MODZ,
	ERR_BOP_PCHAR_INV,
	ERR_BOP_PCHAR_EMP
} ERRNO;
void throw(ERRNO errno, char *str);

/**
 * enum XIXO - Pile type
 * @LIFO: Last in First out: a stack
 * @FIFO: First in First out: a queue
 */
typedef enum XIXO
{
	LIFO, /* stack */
	FIFO  /* queue */
} XIXO;

/**
 * struct ParserInfo - Data stored and needed by the parser
 * @hndl: script handle
 * @lno: current line number
 * @ln: current line
 * @lnlen: current line length
 * @arg_set: whether an argument was provided
 * @arg: argument provided
 */
typedef struct ParserInfo
{
	i32 hndl;
	u32 lno;
	char *ln;
	size_t lnlen;

	i8 arg_set;
	i32 arg;
} ParserInfo;

ParserInfo *parser_info(void);
i32 parse_file(FILE *handle);

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
} stack_t;

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
} instruction_t;

/**
 * struct XIXOData - Pile data
 * @top: top of the pile
 * @bot: bottom of the pile
 * @len: length of the pile
 * @mode: xixo mode of the pile
 */
typedef struct XIXOData
{
	stack_t *top;
	stack_t *bot;
	u32 len;
	XIXO mode;
} XIXOData;
XIXOData *xixo_data(void);
stack_t *xixo_push(i32 v);
i32 xixo_pop(void);

void bop_stack(stack_t **stack, u32 lno);
void bop_queue(stack_t **stack, u32 lno);

void bop_push(stack_t **stack, u32 lno);
void bop_pop(stack_t **stack, u32 lno);
void bop_nop(stack_t **stack, u32 lno);
void bop_swap(stack_t **stack, u32 lno);
void bop_rotl(stack_t **stack, u32 lno);
void bop_rotr(stack_t **stack, u32 lno);

void bop_pall(stack_t **stack, u32 lno);
void bop_pint(stack_t **stack, u32 lno);
void bop_pchar(stack_t **stack, u32 lno);
void bop_pstr(stack_t **stack, u32 lno);

void bop_add(stack_t **stack, u32 lno);
void bop_sub(stack_t **stack, u32 lno);
void bop_mul(stack_t **stack, u32 lno);
void bop_div(stack_t **stack, u32 lno);
void bop_mod(stack_t **stack, u32 lno);



void quit(u32 status);

#define Parser (parser_info())
#define Pile (xixo_data())
#endif /* MAIN_H */
