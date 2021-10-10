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

void RDisplay(struct node *head)
{
    if (head)
    {
        printf("%d ", head->data);
        return RDisplay(head->next);
    }
    return;
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

int RCount(struct node *head)
{
    static int count = 0;
    if (head)
    {
        count++;
        return RCount(head->next);
    }
    return count;
}

int Sum(struct node *head)
{
    int sum = 0;
    while (head)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int RSum(struct node *head)
{
    if (head)
        return RSum(head->next) + head->data;
    return 0;
}

int main()
{

    int A[7] = {0, 1, 2, 3, 4, 5, 6};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 7);
    RDisplay(head);
    printf("\n%d ", Count(head));
    printf("\n%d ", RSum(head));
    return 0;
}