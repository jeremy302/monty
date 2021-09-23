typedef enum BYTE_OPCODE
{
	BOP_STACK, /* lifo mode */
	BOP_QUEUE, /* fifo mode */

	BOP_PUSH, /* add {0} to top of stack */
	BOP_POP, /* remove top of stack */
	BOP_NOP, /* nothing */
	BOP_SWAP, /* swaps top 2 */
	BOP_ROTL, /* moves $0 to $-1 */
	BOP_ROTR, /* moves $-1 to $0 */

	BOP_PALL, /* prints stack */
	BOP_PINT, /* prints top */
	BOP_PCHAR, /* print $0 as char */
	BOP_PSTR, /* print stack as char * till a 0 or end */

	BOP_ADD, /* adds top 2 */
	BOP_SUB, /* subtract $0 from $1 */
	BOP_MUL, /* multiply $0 with $1 */
	BOP_DIV, /* divide $1 by $0 */
	BOP_MOD, /* modulo of $1 divided by $0 */
} BOPCODE;
