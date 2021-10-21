#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

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

void Preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    struct node *head = NULL;

    head = tcreate(head);
    Preorder(head);
    return 0;
}