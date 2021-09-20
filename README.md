# push_swap
*Because swap_push isn’t as natural* 🌳

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
| ``sa`` | Swap the first two elements in stack ``a`` |
| ``sb`` | Swap the first two elements in stack ``b`` |
| ``ss`` | Performs ``sa`` and ``sb`` simultaneously |
| ``ra`` | Rotates all elements upwards so that the first element of ``a`` goes to the bottom of the stack |
| ``rb`` | Rotates all elements upwards so that the first element of ``b`` goes to the bottom of the stack |
| ``rr`` | Performs ``ra`` and ``rb`` simultaneously |
| ``rra`` | Rotates all elements downwards so that the last element of ``a`` goes to the top of the stack |
| ``rrb`` | Rotates all elements downwards so that the last element of ``b`` goes to the top of the stack |
| ``rrr`` | Performs ``rra`` and ``rrb`` simultaneously |

As with other projects, we must verify a few errors, namely:
* A number cannot be repeated in the stack
* All parameters must be integers, thus no characters will be accepted
* All numbers must be integers, numbers out of this scope will throw an error

If any of these checks fail, the program must end with ``Error\n``.

Here's an example input:
```
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

## Stack Implementation

There are several ways to store and sort the list of numbers. Some worked on simple arrays of ints, with the caveat of having no apparent end to the array. Others re-made the linked list implementation from our [libft](https://github.com/madebypixel02/libft) project, but changing the content from ``void *`` to just an ``int``. I however used the original linked list from ``libft`` as I was quite interested in learning how useful void pointers could be, acting pretty much as a wild card to any variable type.

Of course working with that implementation caused some problems with memory, especially early on. One of the things to keep in mind with the ``void *`` approach at this is that you need to allocate enough memory for every int, and later on free it all. After a few headaches and various segmentation faults I managed to implement various stack-related functions which I thought would be useful later:

| Function | Description |
| :------: | :---------: |
| ``st_pop`` | Deletes the first node of the stack and returns its content |
| ``st_push`` | Creates a new node and adds it to the top of the stack with the given content |
| ``st_printstack_ab`` | prints two stacks side-by-side in a given base, printing dots when one is larger than the other |
| ``st_swap_ab`` | Performs either ``sa`` or ``sb``, printing the move accordingly |
| ``st_swap_ss`` | Performs ``ss`` and prints the move |
| ``st_rotate_ab`` | Performs either ``ra`` or ``rb``, printing the move accordingly |
| ``st_rotate_rr`` | Performs ``rr`` and prints the move |
| ``st_rrotate_ab`` | Performs either ``rra`` or ``rrb``, printing the move accordingly |
| ``st_rrotate_rrr`` | Performs ``rrr`` and prints the move |
| ``st_find`` | Returns the index of the first ocurrence of a number in a stack, or ``-1`` if it's not in the stack |
| ``st_is_ordered`` | Returns ``1`` if the stack is ordered from smallest to largest |
| ``st_to_top`` | Moves (if available) a number to the top in the least number of moves possible |
| ``st_min`` | Returns the node with the minimum number in a stack |
| ``st_max`` | Returns the node with the maximum number in a stack |
| ``st_get_at`` | Returns node in the given index |
| ``st_replace_at`` | Changes content at the given index with the given new content |

## The Sorting Algorithm
When debating the optimal algorithm to sort the elements in a, the idea of splitting into chunks kept popping up. However, I wanted to do something that appealed to me more. I ended up using radix sort, as it's quite simple to code and does a pretty decent job with two stacks. Also this method relies heavily on bitwise operators, so it was a great chance for me to figure out what bitwise is all about :)

### How radix sort works
The idea with this algorithm, is we 
