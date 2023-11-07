#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node *add_two_numbers(node *a, node *b)
{
    node *ans = (node *)malloc(sizeof(node));
    node *current = ans;
    int carry = 0;
    while (a || b || carry)
    {
        int sum = (a ? a->data : 0) + (b ? b->data : 0) + carry;
        carry = sum / 10;
        int digit = sum % 10;

        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = digit;
        new_node->next = NULL;
        current->next = new_node;
        current = current->next;

        if (a)
        {
            a = a->next;
        }

        if (b)
        {
            b = b->next;
        }
    }
    return ans->next;
}
void printList(node *list)
{
    while (list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}
int main()
{
    node *l1 = (node *)malloc(sizeof(node));
    node *l2 = (node *)malloc(sizeof(node));

    l1->data = 2;
    l1->next = (node *)malloc(sizeof(node));
    l1->next->data = 4;
    l1->next->next = (node *)malloc(sizeof(node));
    l1->next->next->data = 9;
    l1->next->next->next = NULL;

    l2->data = 5;
    l2->next = (node *)malloc(sizeof(node));
    l2->next->data = 6;
    l2->next->next = (node *)malloc(sizeof(node));
    l2->next->next->data = 4;
    l2->next->next->next = (node *)malloc(sizeof(node));
    l2->next->next->next->data = 9;
    l2->next->next->next->next = NULL;

    node *result = add_two_numbers(l1, l2);
    printList(result);
    return 0;
}
