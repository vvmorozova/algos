#include <stdio.h>
#include <stdlib.h>
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
int list_len(struct ListNode* node){
    struct ListNode* curr;
    int len;

    len = 0;
    curr = node;
    while (curr)
    {
        curr = curr->next;
        len++;
    }
    return (len);
}

struct ListNode* add_element(struct ListNode* node, int n){
    struct ListNode*    new_node;

    new_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
    if (!new_node)
        return (NULL);
    new_node->next = NULL;
    node->next = new_node;
    new_node->val = n;
    return(new_node);
}

struct ListNode* new_element(int n){
    struct ListNode*    new_node;

    new_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
    if (!new_node)
        return (NULL);
    new_node->next = NULL;
    new_node->val = n;
    return(new_node);
}

struct ListNode* sum(struct ListNode* l1, struct ListNode* l2){
    int mem = 0, summa;
    struct ListNode *rez, *curr1, *curr2, **curr_rez;

    if (l1){
        if (l2){
            summa = l1->val + l2->val + mem;
            mem = summa / 10;
            rez = new_element(summa % 10);
        }
        else
        {
            summa = l1->val + mem;
            mem = summa / 10;
            rez = new_element(summa % 10);
        }
        l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    curr_rez = &rez;
    while (l1){
        if (l2){
            summa = l1->val + l2->val + mem;
            mem = summa / 10;
            add_element(*curr_rez, summa % 10);
        }
        else
        {
            summa = l1->val + mem;
            mem = summa / 10;
            add_element(*curr_rez, summa % 10);
        }
        curr_rez = &((*curr_rez)->next);
        l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return (rez);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int a, b;

    a = list_len(l1);
    b = list_len(l2);
    if (a > b)
        return (sum(l1, l2));
    else
        return (sum(l2, l1));
}

void    print_list(struct ListNode* a){
    struct ListNode* curr;

    curr = a;
    while (curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main(void){
    struct ListNode *a, *b, **curr_a, **curr_b, *rez;

    curr_a = &a;
    curr_b = &b;
    *curr_a = new_element(1);
    add_element(*curr_a, 2);
    curr_a = &((*curr_a)->next);
    add_element(*curr_a, 3);
    *curr_b = new_element(1);
    add_element(*curr_b, 2);
    curr_b = &((*curr_b)->next);
    add_element(*curr_b, 3);
    printf("a ");
    print_list(a);
    printf("b ");
    print_list(b);
    rez = sum(a, b);
    printf("rez ");
    print_list(rez);
}