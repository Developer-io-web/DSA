#include <stdio.h>
#include <stdlib.h>
#include "headers2.h"
#include "stack.h"

struct node *tcreate(struct node *head)
{
    struct node *p, *t, *u;
    struct Queue q;
    create(&q, 100);
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

void Ipreorder(struct node *t)
{
    struct Stack s;
    Stackcreate(&s, 100);
    while (t || !isEmpty(s))
    {
        if (t)
        {
            printf("%d ", t->data);
            push(&s, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&s);
            t = t->rchild;
        }
    }
}
void Iinorder(struct node *t)
{
    struct Stack s;
    Stackcreate(&s, 100);
    while (t || !isEmpty(s))
    {
        if (t)
        {
            push(&s, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&s);
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}

void lvlorder(struct node *p)
{
    struct Queue Q;
    create(&Q, 100);
    printf("%d ", p->data);
    enqueue(&Q, p);
    while (qisEmpty(Q))
    {
        p = dequeue(&Q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&Q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&Q, p->rchild);
        }
    }
}

int Count(struct node *root)
{
    int x, y;
    while (root)
    {
        x = Count(root->lchild);
        y = Count(root->rchild);
        return x + y + 1;
    }
    return 0;
}
int Count2(struct node *root)
{
    if (!root)
        return 0;
    return Count(root->lchild) + Count(root->rchild) + 1;
}
int height(struct node *root)
{
    int x = 0, y = 0;
    while (root)
    {
        x = height(root->lchild);
        y = height(root->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}

int main()
{
    struct node *head = NULL;

    head = tcreate(head);
    lvlorder(head);
    printf("%d\n", Count(head));
    printf("%d\n", Count2(head));
    printf("%d\n", height(head));
    return 0;
}
