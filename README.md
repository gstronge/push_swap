# push_swap

**push_swap** is a project from the 42 curriculum that challenges you to implement a highly efficient sorting algorithm using two stacks and a limited set of operations. The goal is to sort a list of integers with the fewest possible instructions.


---


## Project Overview

The program takes a sequence of integers as input and outputs the shortest sequence of stack operations needed to sort them in ascending order. You are only allowed to use two stacks — `a` and `b` — and a strict set of operations.


## Rules and Constraints

- Stack `a` must be sorted in ascending order using a helper stack `b`.
- Stack `a` is initialized with the input integers.
- Stack `b` starts empty.
- Only specific operations are allowed (see below).
- The program outputs the shortest sequence of valid operations that sort the stack.
- No output is printed if no arguments are passed.
- On invalid input (non-integer, duplicate, out-of-range), print `Error\n` to standard error.

- 100 numbers: must be sorted in less than 700 operations.
- 500 numbers: must be sorted in less than 5500 operations.


## Allowed Stack Operations

| Operation | Description |
|----------|-------------|
| `sa`     | Swap the first two elements of stack `a` |
| `sb`     | Swap the first two elements of stack `b` |
| `ss`     | `sa` and `sb` at the same time |
| `pa`     | Push the top element from `b` to `a` |
| `pb`     | Push the top element from `a` to `b` |
| `ra`     | Rotate stack `a` (first element becomes last) |
| `rb`     | Rotate stack `b` |
| `rr`     | `ra` and `rb` at the same time |
| `rra`    | Reverse rotate stack `a` (last element becomes first) |
| `rrb`    | Reverse rotate stack `b` |
| `rrr`    | `rra` and `rrb` at the same time |


## Concepts & Learning Goals

- Mastering stack operations and data manipulation
- Understanding and implementing efficient sorting algorithms
- Handling algorithmic complexity and optimization
- Writing clean and maintainable C code
- Managing input validation and robust error handling
- Developing modular logic for both simulation (checker) and algorithm (push_swap)


## Compilation

To compile and run the project:

```bash
$ make
$ ./push_swap <random sequence of positive integers>
```


## Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

$ ./push_swap 0 one 2 3
Error
