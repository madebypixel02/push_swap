# push_swap
*Because swap_push isn’t as natural* 🌳

### Table Of Contents
* [Introduction](#introduction)
* [Stack Implementation](#stack-implementation)
* [The Sorting Algorithm](#the-sorting-algorithm)
  * [Bitwise Operators](#bitwise-operators)
  * [How Radix Sort Works](#how-radix-sort-works)
* [Performance](#performance)
* [Optimization](#optimization)
* [Installation](#installation)
* [Summary](#summary)

## Introduction
This project is all about sorting algorithms, but with a twist. We are given two stacks (``a`` and ``b``) and we must do some transformations on them so that all the numbers are sorted in ``a`` such that the top element is the smallest. We must compile an executable ``push_swap`` which will receive as an argument either several integer arguments or one large argument with the different numbers in quotes.

Here are all the possible rotations we can do to help sort our stacks:

| Rotation | Description |
| :------: | :---------: |
| ``sa`` | Swaps the first two elements in stack ``a`` |
| ``sb`` | Swaps the first two elements in stack ``b`` |
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
(or ./push_swap "3 4 1 2 6")

The stack should look like this:

3		.		
4		.		
1		.		
2		.		
6		.		
----------	----------
a		b

```
And here are some incorrect inputs:
```shell
./push_swap 3 4 1 2 3
Error

./push_swap 3 4 1 2 six
Error

./push_swap 3 4 1 2 2147483648
Error
```

Once everything has been checked, the program must print out a proposed set of instructions to sort the given numbers in the least number of steps, for example:
```shell
./push_swap 2 1 0
sa
rra
```

## Stack Implementation

There are several ways to store and sort the list of numbers. Some worked on simple arrays of ints, with the caveat of having no apparent end to the array. Others re-made the linked list implementation from our [libft](https://github.com/madebypixel02/libft) project, but changing the content from ``void *`` to just an ``int``. I however used the original linked list from ``libft`` as I was quite interested in learning how useful void pointers could be, acting as a wild card to any variable type.

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

When debating the optimal algorithm to sort the elements in ``a``, the idea of splitting into chunks kept coming up. However, I wanted to do something that appealed to me more. I ended up diving into radix sort, as it's quite simple to code and does a pretty decent job with two stacks. Also this method relies heavily on bitwise operators, so it was a great chance for me to figure out what bitwise is all about :)

Note: crredits to [this medium](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) that helped me understand radix sort and bitwise operators.\

### Bitwise Operators

The two bitwise operators we'll use are ``>>`` and ``&``.

The ``&`` operator compares similarly to ``&&``, and will return 1 if both elements in the comparison are 1:

```
1 & 1 = 1
0 & 1 = 0
1 & 0 = 0
0 & 0 = 0
```

The ``>>`` operator right-shifts the number to the left a certain number of bytes:

```
1010 >> 0 = 1010
1010 >> 1 = 101
1010 >> 2 = 10
1010 >> 3 = 1
1010 >> 4 = 0
```

### How Radix Sort Works

* General Idea

The idea with this algorithm is we take the multiples of two from ``a`` and pass them to ``b``, and rotate the others. Then we bring those elements from ``b`` back to ``a``. Then we right-shift the number one position and again pass the shifted multiples of two from ``a`` to ``b``, and then back to ``a``. Eventually, right-shifting a number too far will leave the number at zero. This way we determine the end of the algorithm. From here we return any remaining elements from stack ``b`` back to ``a`` and *voila*! All the numbers will be sorted.

* Making stack all positive for radix sort

To work with this algorithm, we must make all of our numbers positive. For this I have a function that takes the minimum element and changes it to zero. Then it takes the next smallest and makes it 1. Then keeps doing the same for every element so that all elements are positive and the max value will always be ``stack_len - 1``. Here's an example:
```
./push_swap 5 -4 4 -5 2

Original Stack

5		.		
-4		.		
4		.		
-5		.		
2		.		
----------	----------
a		b

Stack after making all positive

4		.		
1		.		
3		.		
0		.		
2		.		
----------	----------
a		b

The length of the stack is 5, so 5 - 1 = 4 is the maximum value of our translated stack
```

* Radix sort in our stacks

Here is a short demonstration of how the code will work with both stacks to sort the numbers:

Note: some parts are printed in binary for better visualization.

```
Command: ./push_swap 7 5 0 -7 1 -5 -1
```

1. Take an input stack and convert it as before so that all numbers are positive.
```
Original

7		.		
5		.		
0		.		
-7		.		
1		.		
-5		.		
-1		.		
----------	----------
a		b

Translated

6		.		
5		.		
3		.		
0		.		
4		.		
1		.		
2		.		
----------	----------
a		b

Binary

110		.		
101		.		
011		.		
000		.		
100		.		
001		.		
010		.		
----------	----------
a		b
```
2. Check which elements have a zero in the last bit and pass them to stack b, and rotate the rest.
```
101		010		
011		100		
001		000		
.		110		
----------	----------
a		b
```
3. Push elements from b back to a.
```
110		.		
000		.		
100		.		
010		.		
101		.		
011		.		
001		.		
----------	----------
a		b
```
4. Check which elements have a zero in the second bit from the right and pass them to stack b, and rotate the rest.
```
110		001		
010		101		
011		100		
.		000		
----------	----------
a		b
```
5. Push elements from b back to a.
```
000		.		
100		.		
101		.		
001		.		
110		.		
010		.		
011		.		
----------	----------
a		b
```
6. Check which elements have a zero in the third bit from the right and pass them to stack b, and rotate the rest.
```
100		011		
101		010		
110		001		
.		000		
----------	----------
a		b
```
7. Push elements from b back to a.
```
000		.		
001		.		
010		.		
011		.		
100		.		
101		.		
110		.		
----------	----------
a		b
```
8. Stack is sorted!
```
0		.		
1		.		
2		.		
3		.		
4		.		
5		.		
6		.		
----------	----------
a		b
```

Output
```
❯ ./push_swap 7 5 0 -7 1 -5 -1
pb
ra
ra
pb
pb
ra
pb
pa
pa
pa
pa
ra
pb
pb
ra
pb
ra
pb
pa
pa
pa
pa
pb
ra
ra
pb
ra
pb
pb
pa
pa
pa
pa
```

## Performance

As I said before, this algorithm isn't the fastest one, yet it does a pretty good job overall. Here are the average moves needed to sort stacks of different sizes:

| Stack Size | Average Instructions to Sort |
| :--------: | :--------------------------: |
| 3 | 1 |
| 5 | 4 |
| 10 | 64 |
| 100 | 1083 |
| 500 | 6784 |

Note: These numbers were obtained using [push_swap_tester](https://github.com/lmalki-h/push_swap_tester)

## Optimization

This algorithm is pretty straightforward, and there are only a handful of ways to optimize it. First of all, I made a special case for sorting 7 numbers or less, which uses a more efficient algorithm than radix-sort, sorting three numbers in less than 2 steps. To *actually* optimize radix, sort, I tried a few things:

* Don't push the bottom elements from a to b if they're already in place
* Don't push the botttom elements from b to a if they're already in place
* Check if the stack is already sorted before pushing to b
* TBA

## Installation

* Cloning the repositories

```shell
git clone https://github.com/madebypixel02/push_swap.git
cd push_swap
git clone https://github.com/madebypixel02/libft.git
```

* Testing the function

As with previous projects, this one includes a Makefile which compiles the sources into the ``push_swap`` executable. Here are the basic make rules you can use:

```
make                         Compiles the entire project
make norminette              Passes Norminette to all files that need to pass Norminette
make test N={No_of_elems}    Randomly chooses N elements from -N to N and passes it to push_swap,
                             then returns the number of moves and the result of the checker
```

* Example

![make test Example](https://user-images.githubusercontent.com/40824677/134048840-1360d954-cfb4-44e9-b850-299814eda2ee.png)

## Summary

This project was filled with new concepts for me (void pointers, bitwise operators, sorting algorithms, ...), so it was a rollercoaster of emotions. Still, even though it isn't the most optimal sorting algorithm, I believe I learned a lot making it!

September 20th, 2021
