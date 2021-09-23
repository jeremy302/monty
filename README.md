# Monty Project
This is a monty bytecode intepreter written in C. The following opcodes are available:


| Opcode         | Description                                        |
|----------------|----------------------------------------------------|
| `stack`        | treats the pile as a stack (LIFO)                  |
| `queue`        | treats the pile as a queue (FIFO)                  |
| `push integer` | pushes an integer to the top of the pile           |
| `pop`          | removes the top element                            |
| `nop`          | do nothing                                         |
| `swap`         | swaps the top 2 elements                           |
| `rotl`         | sends the top element to the bottom                |
| `rotr`         | sends the bottom element to the top                |
| `pall`         | prints all integers in the stack                   |
| `pint`         | print the top element                              |
| `pchar`        | prints the top element as an ascii character       |
| `pstr`         | starts printing from the top element as a string   |
| `add`          | adds the top 2 elements                            |
| `sub`          | subtracts the top element from the second          |
| `mul`          | multiplies the top 2 elements                      |
| `div`          | divides the second element by the top              |
| `mod`          | the remainder when the top element divides the 2nd |
