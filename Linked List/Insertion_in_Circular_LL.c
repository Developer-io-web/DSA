#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Create(struct node *head, int *A, int n)
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

    struct node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
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

struct node *Insert(struct node *head, int pos, int num)
{
    struct node *p, *t;
    p = head;
    if (pos < 0 || pos > Len(head))
    {
        return head;
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->next = NULL;

    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    return head;
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head = Create(head, A, n);
    head = Insert(head, 0, 5);
    Display(head);
    return 0;
}