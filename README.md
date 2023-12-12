## *0x1B. C - Sorting algorithms & Big O*

`C`   `Algorithm`   `Data structure`

By: Alexandre Gautier

![image](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/248/willy-wonka.png)

## *Resources:*

Read or watch:

- [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation)
- [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
- [15 sorting algorithms in 6 minutes (WARNING: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)
- [CS50 Algorithms explanation in detail by David Malan](https://www.youtube.com/watch?v=kPRA0W1kECg)
- [All about sorting algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)

## *General:*

- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

## *Data Structure and Functions:*

For this project you are given the following `print_array`, and `print_list` functions:
```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```
```
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

- Our files `print_array.c` and `print_list.c` (containing the `print_array` and `print_list` functions) will be compiled with your functions during the correction.
- Please declare the prototype of the functions `print_array` and `print_list` in your `sort.h` header file
- Please use the following data structure for doubly linked list:

```
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## *Tests:*

Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://www.random.org/integer-sets/)


## *Tasks:*

#### [0. Bubble sort](0-bubble_sort.c)

https://youtu.be/lyZQPjUT5B4

Write a function that sorts an array of integers in ascending order using the [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm

- Prototype: `void bubble_sort(int *array, size_t size);`
- You’re expected to print the `array` after each time you swap two elements

Write in the file `0-O`, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [1. Insertion sort](1-insertion_sort_list.c)

Write a function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) algorithm

- Prototype: `void insertion_sort_list(listint_t **list);`
- You are not allowed to modify the integer `n` of a node. You have to swap the nodes themselves.
- You’re expected to print the `list` after each time you swap two elements

Write in the file `1-O`, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [2. Selection sort](2-selection_sort.c)

Write a function that sorts an array of integers in ascending order using the [Selection sort](https://en.wikipedia.org/wiki/Selection_sort) algorithm

- Prototype: `void selection_sort(int *array, size_t size);`
- You’re expected to print the `array` after each time you swap two elements

Write in the file `2-O`, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [3. Quick sort](3-quick_sort.c)

Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm

- Prototype: `void quick_sort(int *array, size_t size);`
- You must implement the `Lomuto` partition scheme.
- The pivot should always be the last element of the partition being sorted.
- You’re expected to print the `array` after each time you swap two elements

Write in the file `3-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [4. Shell sort - Knuth Sequence](100-shell_sort.c)

Write a function that sorts an array of integers in ascending order using the [Shell sort](https://en.wikipedia.org/wiki/Shellsort) algorithm, using the `Knuth sequence`

- Prototype: `void shell_sort(int *array, size_t size);`
- You must use the following sequence of intervals (a.k.a the Knuth sequence):
   - `n+1 = n * 3 + 1`
   - `1, 4, 13, 40, 121, ...`
- You’re expected to print the `array` each time you decrease the interval

### No big O notations of the time complexity of the Shell sort (Knuth sequence) algorithm needed - as the complexity is dependent on the size of array and gap


#### [5. Cocktail shaker sort](101-cocktail_sort_list.c)

Write a function that sorts a doubly linked list of integers in ascending order using the [Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort) algorithm

- Prototype: `void cocktail_sort_list(listint_t **list);`
- You are not allowed to modify the integer `n` of a node. You have to swap the nodes themselves.
- You’re expected to print the `list` after each time you swap two elements 

Write in the file `101-O`, the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [6. Counting sort](102-counting_sort.c)

Write a function that sorts an array of integers in ascending order using the [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) algorithm

- Prototype: `void counting_sort(int *array, size_t size);`
- You can assume that `array` will contain only numbers `>= 0`
- You are allowed to use `malloc` and `free` for this task
- You’re expected to print your counting array once it is set up
   - This array is of size `k + 1` where `k` is the largest number in `array`

Write in the file `102-O`, the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [7. Merge sort](103-merge_sort.c)

Write a function that sorts an array of integers in ascending order using the [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm

- Prototype: `void merge_sort(int *array, size_t size);`
- You must implement the `top-down` merge sort algorithm
   - When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
    - Sort the left array before the right array
- You are allowed to use `printf`
- You are allowed to use `malloc` and `free` only once (only one call)

Write in the file `103-O`, the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [8. Heap sort](104-heap_sort.c)

Write a function that sorts an array of integers in ascending order using the [Heap sort](https://en.wikipedia.org/wiki/Heapsort) algorithm

- Prototype: `void heap_sort(int *array, size_t size);`
- You must implement the `sift-down` heap sort algorithm
- You’re expected to print the `array` after each time you swap two elements 

Write in the file `104-O`, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [9. Radix sort](105-radix_sort.c)

Write a function that sorts an array of integers in ascending order using the [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) algorithm

- Prototype: `void radix_sort(int *array, size_t size);`
- You must implement the `LSD` radix sort algorithm
- You can assume that `array` will contain only numbers >= 0
- You are allowed to use `malloc` and `free` for this task
- You’re expected to print the array each time you increase your `significant digit`


#### [10. Bitonic sort](106-bitonic_sort.c)

Write a function that sorts an array of integers in ascending order using the [Bitonic sort](https://en.wikipedia.org/wiki/Bitonic_sorter) algorithm

- Prototype: `void bitonic_sort(int *array, size_t size);`
- You can assume that `size` will be equal to `2^k`, where `k >= 0` (when `array` is not `NULL` …)
- You are allowed to use `printf`
- You’re expected to print the `array` each time you swap two elements

Write in the file `106-O`, the big O notations of the time complexity of the Bitonic sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case


#### [11. Quick Sort - Hoare Partition scheme](107-quick_sort_hoare.c)

Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm

- Prototype: `void quick_sort_hoare(int *array, size_t size);`
- You must implement the `Hoare` partition scheme.
- The pivot should always be the last element of the partition being sorted.
- You’re expected to print the `array` after each time you swap two elements

Write in the file `107-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

#### [12. Dealer](1000-sort_deck.c)

Write a function that sorts a deck of cards.

- Prototype: `void sort_deck(deck_node_t **deck);`
- You are allowed to use the C standard library function `qsort`
- Please use the following data structures:
```
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;
```
- You have to push you `deck.h` header file, containing the previous data structures definition
- Each node of the doubly linked list contains a card that you cannot modify. You have to swap the nodes.
- You can assume there is exactly `52` elements in the doubly linked list.
- You are free to use the sorting algorithm of your choice
- The deck must be ordered:
   - From `Ace` to `King`
   - From Spades to Diamonds





-----------------
## Author 📑:

[MOHAMMED CHAKIR](https://github.com/mohammedchakir)
