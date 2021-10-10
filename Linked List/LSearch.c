#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *Create(int *A, struct node *head, int n)
{
    head = (struct node *)malloc(sizeof(struct node));

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

struct node *LSearch(struct node *head, int num)
{
    struct node *prev, *p;
    p = head;
    while (p)
    {
        if (p->data == num)
        {
            prev->next = p->next;
            p->next = head;
            head = p;
            return head;
        }
        prev = p;
        p = p->next;
    }
}

int main()
{

    int A[7] = {0, 1, 2, 3, 4, 5, 6};

    head = Create(A, head, 7);
    Display(head);
    head = LSearch(head, 6);
    head = LSearch(head, 1);
    printf("\n%d\n", head->data);
    Display(head);
    return 0;
}