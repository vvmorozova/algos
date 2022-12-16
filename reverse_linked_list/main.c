/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rev(struct ListNode* curr)
{
    struct ListNode    *nx, *rez, *iter;

    if (curr->next)
        rez = rev(curr->next);
    else
        return (curr);
    iter = rez;
    while (iter->next)
        iter = iter->next;
    iter->next = curr;
    curr->next = NULL;
    return (rez);
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode     *next, *curr;

    if (!head || !head->next)
        return (head);
    return (rev(head));
}