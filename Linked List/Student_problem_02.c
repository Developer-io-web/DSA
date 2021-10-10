#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Create(struct node *head, int *A, int n)
{
    struct node *t, *last;
    head->data = A[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        last->next = t;
        t->next = NULL;
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

void FindMid(struct node *head)
{
    struct node *q, *p;
    p = q = head;
    while (p)
    {
        p = p->next;
        if (p)
            p = p->next;
        if (p)
            q = q->next;
    }
    printf("%d ", q->data);
}

int main()
{
    int a[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = Create(head, a, n);
    // Display(head);
    FindMid(head);

    return 0;
}