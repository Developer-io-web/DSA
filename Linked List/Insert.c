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

struct node *Insert(struct node *head, int pos, int num)
{
    struct node *p, *q;
    p = head;
    q = (struct node *)malloc(sizeof(struct node));
    if (!(pos >= 0 && pos <= Count(head)))
    {
        // printf("%d\n", Count(head));
        // printf("%d", pos);
        return 0;
    }

    q->data = num;
    if (pos == 0)
    {
        q->next = head;
        head = q;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
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
    head = Insert(head, 7, 8);
    Display(head);
    return 0;
}