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

struct node *InsertSort(struct node *head, int num)
{
    struct node *p, *q, *t;
    p = head;
    q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->next = NULL;

    if (head == NULL)
    {
        head = t;
        return head;
    }
    while (p && p->data < num)
    {
        q = p;
        p = p->next;
    }
    if (p == head)
    {
        t->next = head;
        head = t;
        return head;
    }
    else
    {
        t->next = q->next;
        q->next = t;
        return head;
    }
}

int main()
{

    int A[7] = {1, 3, 4, 5, 6};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 5);
    Display(head);
    printf("\n\n\n");
    head = InsertSort(head, 2);
    head = InsertSort(head, 0);
    Display(head);
    return 0;
}