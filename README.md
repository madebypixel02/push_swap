# push_swap
*Because swap_push isn’t as natural*

### Table Of Contents
* [Introduction](#introduction)
* [Stack Implementation](#stack-implementation)
* [The Sorting Algorithm](#the-sorting-algorithm)
* [Optimization](#optimization)
* [Installation](#installation)
* [Summary](#summary)

## Introduction
This project is all about sorting algorithms, but with a twist. We are given two stacks (``a`` and ``b``) and we must do some transformation so that all the numbers are sorted in a such that the top element is the smallest. We must compile an executable ``push_swap`` which will receive as an argument either several integer arguments or one large argument with the different numbers in quotes.

Here are all the possible rotations we can do to help sort our stacks:

| Rotation | Description |
| :------: | :---------: |
| sa | Swap the first two elements in stack ``a`` |
| sb | Swap the first two elements in stack ``b`` |
| ss | Performs ``sa`` and ``sb`` simultaneously |
| ra | Rotates all elements upwards so that the first element of ``a`` goes to the bottom of the stack |
| rb | Rotates all elements upwards so that the first element of ``b`` goes to the bottom of the stack |
| rr | Performs ``ra`` and ``rb`` simultaneously |
| rra | Rotates all elements downwards so that the last element of ``a`` goes to the top of the stack |
| rrb | Rotates all elements downwards so that the last element of ``b`` goes to the top of the stack |
| rrr | Performs ``rra`` and ``rrb`` simultaneously |

As with other projects, we must verify a few errors, here are a few of them:
* A number cannot be repeated in the stack
* All parameters must be integers, thus no characters will be accepted
* All numbers must be integers, numbers out of this scope will throw an error

If any of these checks fail, the program must end with ``Error\n``.

Here's an example input:
```shell
./push_swap 3 4 1 2 6

The stack should look like this:

3		.		
4		.		
1		.		
2		.		
6		.		
----------	----------
a		b

```
And here's an incorrect input:
```shell
./push_swap 3 4 1 2 3
Error
```

Once everything has been checked, the program must print out a proposed set of instructions to sort the given numbers in the least number of steps, for example:
```shell
./push_swap 2 1 0
sa
rra
```
