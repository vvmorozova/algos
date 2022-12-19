/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct hash_s;
struct hash_s {
    struct ListNode *val;
    struct hash_s   *next;
 };

#define SIZE 100
int hash_func(struct ListNode *curr)
{
    return ((size_t)curr % SIZE);
}

//free mem 
void    free_mem(struct hash_s *table[SIZE])
{
    struct hash_s *curr, *nx;
    for (int i = 0; i < SIZE; i++) {
        if (table[i]) {
            curr = table[i];
            nx = curr->next;
        }
        while (curr->next) {
            free(curr);
            curr = nx;
            nx = nx->next;
        }
        free(curr);
    }
}

struct ListNode *detectCycle(struct ListNode *head)
{
    struct hash_s *table[SIZE], *curr;
    int k;

    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
    while (head) {
        k = hash_func(head);
        //printf("%d ", k);
        if (!table[k]) {
            table[k] = (struct hash_s *)malloc(sizeof(struct hash_s));
            table[k]->val = head;
            table[k]->next = NULL;
            head = head->next;
            continue;
        }
        curr = table[k];
        while (curr->next) {
            if (curr->val == head) {
                free_mem(table);
                return (head);
            }
            curr = curr->next;
        }
        if (curr->val == head) {
            free_mem(table);
            return (head);
        }
        curr->next = (struct hash_s *)malloc(sizeof(struct hash_s));
        curr = curr->next;
        curr->val = head;
        curr->next = NULL;
        head = head->next;
    }
    free_mem(table);
    return (NULL);
}