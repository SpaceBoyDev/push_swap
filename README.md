_This project has been created as part of the 42 curriculum by darmarti_

# push_swap

## Description

`push_swap` is a 42 algorithm project that sorts a stack of integers using a
second stack and a restricted instruction set. The program writes the
operations needed to sort stack `A` in ascending order, using the Turkish
cost-based algorithm implemented in `algorithm.c`.

The input may be passed as separate arguments or as one space-separated
string. Duplicate values, invalid numbers and out-of-range integers are
rejected.

## Build

Requirements: a Unix-like system, `cc`, `make`, and the project `libft`.

```bash
make
```

Useful targets:

```bash
make clean    # Remove object files
make fclean   # Remove objects and the executable
make re       # Rebuild from scratch
make norme    # Run Norminette on the project files
```

## Usage

```bash
./push_swap 4 67 3 87 23
```

or:

```bash
./push_swap "4 67 3 87 23"
```

The output is a newline-separated sequence of valid operations. It can be
checked with the bonus checker when available:

```bash
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
```

The checker should print `OK` for a correctly sorted result.

## Instruction set

- `sa`, `sb`, `ss`: swap the first two elements of one or both stacks.
- `pa`, `pb`: push the top element between stacks.
- `ra`, `rb`, `rr`: rotate one or both stacks upwards.
- `rra`, `rrb`, `rrr`: reverse-rotate one or both stacks.

## Implementation

- `stack_initialization.c`: parses and validates input values.
- `nodes.c`, `node_utils.c`, `update_nodes.c`: maintains linked-list metadata,
  targets, costs and stack positions.
- `algorithm.c`: selects inexpensive moves and sorts both stacks.
- `moves.c`, `push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c`: implements
  the allowed operations.
- `libft/`: supporting 42 C library.
