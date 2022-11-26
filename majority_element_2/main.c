/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// src: leetcode
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

struct s_major;
typedef struct s_major{
    int value;
    int amount;
    struct s_major *next;
} major;

void    init_table(major **hash_table)
{
    for (int i = 0; i < SIZE; i++)
        hash_table[i] = NULL;
}

int hash_func(int val)
{
    int rez;

    rez = abs(val) % SIZE;
    return (rez);
}

major    *add_elem(major *hash_table, int value)
{
    major *ptr, *new;

    ptr = hash_table;

    while (ptr && ptr->next) {
        if (ptr->value == value) {
            ptr->amount++;
            return (hash_table);
        }
        ptr = ptr->next;
    }
    if (ptr && ptr->value == value) {
        ptr->amount++;
        return (hash_table);
    }
    new = malloc(sizeof(major));
    new->next = NULL;
    new->value = value;
    new->amount = 1;
    if (ptr) {
        ptr->next = new;
    }
    else
        hash_table = new;
    return (hash_table);
}

major **count_retsize(major **hash_table, int size, int *ret)
{
    int min = size / 3;
    int j = 0;
    major *curr;

    for (int i = 0; i < SIZE; i++) {
        curr = hash_table[i];
        while (curr) {
            if (curr->amount > min)
                j++;
            curr = curr->next;
        }
    }
    *ret = j;
    return (hash_table);
}

major **fill_rez(major **hash_table, int **rez, int size)
{
    int min = size / 3;
    int j = 0;
    major *curr;

    for (int i = 0; i < SIZE; i++) {
        curr = hash_table[i];
        while (curr) {
            if (curr->amount > min)
                (*rez)[j++] = curr->value;
            curr = curr->next;
        }
    }
    return (hash_table);
}

void    free_table(major *hash_table[SIZE])
{
    major *curr, *prev;

    for (int i = 0; i < SIZE; i++) {
        curr = hash_table[i];
        while (curr) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }
    free(hash_table);
}

void    print_table(major **hash_table)
{
    major *curr;

    for (int i = 0; i < SIZE; i++) {
        curr = hash_table[i];
        while (curr)
            curr = curr->next;
        if (hash_table[i])
            printf("---\n");
    }
}

int* majorityElement(int* nums, int numsSize, int* returnSize){
    major   **hash_table;
    int     *rez;

    hash_table = malloc(sizeof(major *) * SIZE);
    init_table(hash_table);
    for (int i = 0; i < numsSize; i++)
        hash_table[hash_func(nums[i])] = add_elem(hash_table[hash_func(nums[i])], nums[i]);
    hash_table = count_retsize(hash_table, numsSize, returnSize);
    // print_table(hash_table);
    rez = (int *)malloc(sizeof(int) * (*returnSize));
    hash_table = fill_rez(hash_table, &rez, numsSize);
    free_table(hash_table);
    return (rez);
}