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

struct node *LLRotation(struct node *p)
{
    struct node *pl = p->left;
    struct node *plr = pl->right;
    pl->right = p;
    p->left = plr;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

struct node *LRRotation(struct node *p)
{
    struct node *pl = p->left;
    struct node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    plr->height = Nodeheight(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

struct node *RInsert(struct node *p, int key)
{
    struct node *r = NULL;
    if (p == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = key;
        r->left = r->right = NULL;
        r->height = 1;
        return r;
    }
    else if (key > p->data)
    {
        p->right = RInsert(p->right, key);
    }
    else if (key < p->data)
    {
        p->left = RInsert(p->left, key);
    }

    p->height = Nodeheight(p);

    if (BF(p) == 2 && BF(p->left) == 1)
    {
        return LLRotation(p);
    }
    if (BF(p) == 2 && BF(p->left) == -1)
    {
        return LRRotation(p);
    }
    return p;
}

int main()
{
    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);
    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    return 0;
}