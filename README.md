# push_swap
Project from 42 School, AI & Algorithms branch

Given any initial stack of integers, sort in ascending order using only a second stack through a limited predefined set of instructions.

A first program should output the optimal set of instructions (i.e. that sorts the stack in the least number of movements).
A second program should take the outputted set of instructions and apply it, checking that it does indeed sort the stack correctly.

## Instruction set

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

## Compiling
Run `make`.

## Running push_swap
```
./push_swap [-t] 10 -2 35 40 0
```
Push_swap generates the optimal list of instructions to sort the integers. Use -t to display number of operations. 

## Running checker
```
ARG="10 -2 35 40 0"; ./push_swap $ARG | ./checker [-v] $ARG
```
Checker takes the list of instructions generated and applies it to the list of integers, checking that it does indeed sort it. Use -v to display the two stacks at each operation.

