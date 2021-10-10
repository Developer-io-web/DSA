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

struct node *Reverse(struct node *head)
{
    struct node *p = head;
    while (p)
    {
        struct node *temp;
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == NULL)
        {
            head = p;
        }
    }
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    head = Create(head, A, n);
    head = Reverse(head);
    Display(head);
    return 0;
}