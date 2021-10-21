#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

void Insert(int num)
{
    struct node *p = root;
    struct node *t, *r = NULL;

    if (root == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;
        t->lchild = t->rchild = NULL;
        root = t;
        return;
    }
    while (p != NULL)
    {
        r = p;
        if (num > p->data)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->lchild = t->rchild = NULL;
    if (num > r->data)
    {
        r->rchild = t;
    }
    else
    {
        r->lchild = t;
    }
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

struct node *Search(int key)
{
    struct node *p = root;
    while (p)
    {
        if (p->data == key)
        {
            return p;
        }
        else if (key > p->data)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    return 0;
}

int main()
{
    struct node *temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(15);
    Insert(40);
    Inorder(root);

    temp = Search(40);
    if (temp)
    {
        printf("\nElement %d is Found \n", temp->data);
    }
    else
    {
        printf("\nElement not Found \n", temp->data);
    }

    return 0;
}