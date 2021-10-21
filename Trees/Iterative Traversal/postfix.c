#include <stdio.h>
#include <stdlib.h>
#include "headers2.h"
#include "stack2.h"

struct node *tcreate(struct node *head)
{
    struct node *p, *t, *u;
    struct Queue q;
    create(&q);
    int x;
    printf("Enter the value of root node : ");
    scanf("%d", &x);
    head = (struct node *)malloc(sizeof(struct node));
    head->data = x;
    head->lchild = NULL;
    head->rchild = NULL;
    enqueue(&q, head);
    while (q.front != q.rear)
    {
        p = dequeue(&q);

        t = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of Left child of %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        u = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of right child of %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            u->data = x;
            u->lchild = NULL;
            u->rchild = NULL;
            p->rchild = u;
            enqueue(&q, u);
        }
    }
    return head;
}

void Ipostorder(struct node *t)
{
    struct Stack s;
    Stackcreate(&s, 100);
    long int temp;
    while (t || !isEmpty(s))
    {
        if (t)
        {
            push(&s, (long int)t);
            t = t->lchild;
        }
        else
        {
            temp = pop(&s);
            if (temp > 0)
            {
                push(&s, -temp);
                t = (struct node *)temp;
                t = t->rchild;
            }
            else
            {
                temp = -temp;
                printf("%d ", ((struct node *)temp)->data);
                t = NULL;
            }
        }
    }
}

int main()
{
    struct node *head = NULL;

    head = tcreate(head);
    Ipostorder(head);
    return 0;
}