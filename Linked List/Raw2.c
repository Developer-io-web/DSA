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
    head->next = head;

    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    return head;
}

void Display(struct node *head)
{
    struct node *t = head;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
}

int Len(struct node *head)
{
    struct node *p = head;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

int main()
{

    int A[7] = {0, 1, 2, 3, 4, 5, 6};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 7);
    RDisplay(head, head);
    return 0;
}