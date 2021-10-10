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

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    head = Create(head, A, n);
    Display(head);
    printf("\n%d", Count(head));
    return 0;
}