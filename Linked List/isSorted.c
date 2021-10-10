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

int isSorted(struct node *head)
{
    int x = INT_MIN;
    while (head)
    {
        if (head->data < x)
        {
            return 0;
        }
        x = head->data;
        head = head->next;
    }
    return 1;
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

    int A[7] = {7, 9, 2, 3, 4, 5, 6};

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(A, head, 7);
    // Display(head);
    if (isSorted(head))
    {
        printf("\nIt is Sorted");
    }
    else
    {
        printf("\nIt is not Sorted");
    }
    return 0;
}