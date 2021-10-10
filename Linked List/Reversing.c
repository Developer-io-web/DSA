#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Create(struct node *head, int A[], int n)
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

int COUNT(struct node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node *Reverse1(struct node *head)
{
    int *A;
    A = (int *)malloc(COUNT(head) * sizeof(int));
    int i = 0;
    struct node *p = head;
    while (p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    i--;
    p = head;
    while (p)
    {
        p->data = A[i];
        i--;
        p = p->next;
    }
    return head;
}

//Using Sliding Pointers

struct node *Reverse2(struct node *head)
{
    struct node *p = head;
    struct node *q, *r;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}

struct node *Reverse3(struct node *head, struct node *q, struct node *p)
{
    if (p)
    {
        Reverse3(p->next, p);
        p->next = q;
    }
    else
    {
        head = q;
    }
    return head;
}

int main()
{
    int A[2] = {90, 100};
    int n = 2;
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = Create(head, A, n);

    head = Reverse2(head);

    Display(head);

    return 0;
}