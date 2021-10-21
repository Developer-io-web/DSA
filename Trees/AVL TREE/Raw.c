#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    int height;
    struct node *right;
} *root = NULL;

int Nodeheight(struct node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BF(struct node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl - hr;
}
