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

int main()
{

    int A[7] = {0, 1, 2, 3, 4, 5, 6};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 7);
    Display(head);
    printf("\n%d ", (head));
    return 0;
}