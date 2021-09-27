,------------------------------------------------>\\ read first charcter and convert it to a digit (0 to 9)
,------------------------------------------------<\\ read second character and convert it to a digit ! pointer at $0

[// while $0
    >[// while $1
        >+>+<<- // copy $1 to $2 an $3
     ]// pointer at $1
    >[// while $2
        <+>- // increment $1 and decrement $2
     ]
    <<- // decrement $0
] // result should be in $3 ! $0 and $1 should be 0 ! pointer at $0
>>[-] // set $2 to 0 ! pointer at $2
>[
    -<<<+>>>
 ]
<<< // copy $3 to $0 ! pointer at $0
$0: num
$1: num_tmp_1
$2: num_tmp_2
$3: divisor
$4: zero_flag
$5: transfer_buf
$6: divisible
$7: quotient
$8: remainder
[
    >>>>> // point at $5: transfer_buf
    [-] // reset to 0
    <<++++++++++ // $$3: divisor ! add 10
    [
        <<< // $$0: num
        [ // transfer num to num_tmp_1 and num_tmp_2
            >+>+<<- // add 1 $1: to num_tmp_1 and $2: num_tmp_2
        ]
        >> $$2: num_tmp_2
        [ // transer num_tmp_2 to num
            <<+>>-
        ]
        >>+ $$4: zero_flag ! add 1
        <<< $$1: num_tmp_1
        [
            >>>- // $$4: zero_flag ! sub 1
            >+ // $$5: transfer_buf ! add 1
            <<<<<- // $$0: num ! sub 1
            > // $$1: num_tmp_1
            [-] // set $1: num_tmp_1 to 0
        ]
        >>> $4: zero_flag
        [
            >>+ // $$6: divisible ! add 1
            <<< // $$3: divisor
            [-] // set $3: divisor to 0
            + // set $3: divisor to 1
            >- // $$4: zero_flag ! sub 1
        ]
        <- // $$3: divisor ! sub 1
    ]
    >+ // $$4: zero_flag ! set 1
    >> // $6: divisble
    [
        <<- // $$4: zero_flag ! set 0
        > // $$5: transfer_buf
        [
            >>>+ // $$8: remainder ! add 1
            <<<- // $$5: transfer_buf ! sub 1
        ]
        >- // $6: divisible ! sub 1
    ]
    << // $$4: zero_flag
    [
        >>>+ // $$7: quotient ! add 1
        <<<- // $$4: zero_flag ! set 0
    ]
    <<<< // $$0
]
>>>>>>> // $$7: quotient ! convert it to ascii and print it if it isn't 0
[
    ++++++++++++++++++++++++++++++++++++++++++++++++.
    [-]
]
// $$8: remainder! print it
>++++++++++++++++++++++++++++++++++++++++++++++++.
> // $$9
++++++++++. // print '\n'