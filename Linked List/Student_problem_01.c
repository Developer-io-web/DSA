// Doubly Circular Linked List .
// Operation on DCLL
// Creation Deletion and Insertion

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
    head->prev = head;
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->prev = last;
        t->next = head;
        last->next = t;
        head->prev = t;
        last = t;
    }
    return head;
}

void Display(struct node *head)
{
    struct node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

int Count(struct node *head)
{
    int count = 0;
    struct node *p = head;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

struct node *Insert(struct node *head, int ind, int num)
{
    struct node *t, *p = head;
    int i;
    if (ind < 0 || ind > Count(head))
        return head;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;

    if (ind == 0)
    {
        t->next = head;
        t->prev = head->prev;
        if (head->prev)
        {
            head->prev->next = t;
        }
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

struct node *Delete(struct node *head, int ind)
{
    struct node *p = head;
    int x = -1;
    if (ind <= 0 || ind > Count(head))
        return head;

    if (ind == 1)
    {
        head = head->next;
        if (head)
        {
            head->prev = p->prev;
        }
        p->prev->next = p->next;
        x = p->data;
        printf("Deleted element is %d \n", x);
        free(p);
    }
    else
    {
        for (int i = 0; i < ind - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        printf("Deleted element is : %d\n", x);
        free(p);
    }
    return head;
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = Create(head, A, n);
    head = Delete(head, 5);
    Display(head);
    return 0;
}