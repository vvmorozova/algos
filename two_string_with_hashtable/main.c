// src: leetcode
// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.

// You can return the answer in any order.
#include <stdio.h>
#include <stdlib.h>

#define MAX 60000000
typedef struct {
    size_t value;
    int num;
} hash;

size_t hash_func(size_t value)
{
    return ((size_t)value + MAX / 6);
}

void    init_hash_table(hash *hash_table[MAX], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        hash_table[i] = NULL;
    }
}

void    add_elem(hash *hash_table[MAX], size_t value, int num)
{
    size_t index;

    index = hash_func(value);
    printf("%llu\n", index);
    hash_table[index] = malloc(sizeof(hash));
    if (! hash_table[index])
        return ;
    hash_table[index]->value = value;
    hash_table[index]->num = num;

}

void    free_table(hash *hash_table[MAX], size_t size)
{
    for (int i = 0; i < size; i++) {
        if (hash_table[i])
            free(hash_table[i]);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hash *hash_table[MAX];
    int* rez = calloc((*returnSize = 2), sizeof(int));
    size_t *nums_copy, target_copy;

    init_hash_table(hash_table, MAX);
    for (int i = 0; i < numsSize; i++) {
        if ((hash_table[hash_func( (size_t)target -  (size_t)nums[i])]) == NULL)
            add_elem(hash_table, (size_t)nums[i], i);
        else {
            rez[0] = hash_table[hash_func( (size_t)target -  (size_t)nums[i])]->num;
            rez[1] = i;
            free_table(hash_table,  (size_t)numsSize);
            return (rez);
        }
    }
    free_table(hash_table,  (size_t)numsSize);
    return (NULL);
}