#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Create(int *A, struct node *head, int n)
{
    struct node *last, *t;
    head->data = A[0];
    head->next = NULL;

    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;
}

void Display(struct node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *Concat(struct node *head, struct node *second)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
    return head;
}

struct node *Merge(struct node *first, struct node *second)
{
    struct node *third, *last;
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first)
    {
        last->next = first;
    }
    if (second)
    {
        last->next = second;
    }
    return third;
}

int main()
{

    int A[7] = {10, 20, 30, 40, 50, 60, 70};
    int B[4] = {5, 15, 25, 35};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 7);
    second = Create(B, second, 4);
    third = Merge(head, second);
    // head = Concat(head, second);
    Display(third);

    return 0;
}