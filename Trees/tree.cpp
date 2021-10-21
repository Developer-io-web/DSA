#include <iostream>
#include <stdio.h>
#include "queuecpp.h"
using namespace std;

class Tree
{
public:
    node *root; //It is made public so that it can be accessed easily.
    void createTree();
    void postorder()
    {
        postorder(root);
    }
    void postorder(node *p); //They all include the arguments cuz they follow the recursive procedures so there must be a argument.
                             // void preorder(node *root);
                             // void inorder(node *root);
};

void Tree::createTree()
{
    node *p, *t;
    int x;
    Queue q(100);
    printf("Enter the Root Node : ");
    scanf("%d", &x);
    root = new node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter the left Node of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("Enter the right Node of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// void Tree::postorder(node *root)
// {
//     while (root)
//     {
//         postorder(root->lchild);
//         postorder(root->rchild);
//         printf("%d ", root->data);
//     }
// }

void Tree::postorder(node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.postorder();
    return 0;
}