#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *Create(struct node *head, int *A, int n)
{
    struct node *last, *t;
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
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

int Count(struct node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node *Insert(struct node *head, int ind, int num)
{
    struct node *p = head, *t;
    if (ind < 0 || ind > Count(head))
    {
        return head;
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    if (ind == 0)
    {
        t->next = head;
        t->prev = NULL;
        head->prev = t;
        head = t;
    }
    else
    {
        for (int i = 0; i < ind - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    head = Create(head, A, n);
    head = Insert(head, 5, 5);
    Display(head);
    return 0;
}