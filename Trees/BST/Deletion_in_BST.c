#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
} *head = NULL;

void Insert(int key)
{
    struct node *p;
    struct node *r = NULL, *q = head;

    if (head == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->left = p->right = NULL;
        head = p;
        return;
    }
    while (q != NULL)
    {
        r = q;
        if (key > q->data)
        {
            q = q->right;
        }
        else if (key < q->data)
        {
            q = q->left;
        }
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->left = p->right = NULL;
    if (key > r->data)
    {
        r->right = p;
    }
    else if (key < r->data)
    {
        r->left = p;
    }
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}

int height(struct node *p)
{
    int h1, h2;
    if (p == NULL)
        return 0;
    h1 = height(p->left);
    h2 = height(p->right);

    return h1 > h2 ? h1 + 1 : h2 + 1;
}

struct node *InPre(struct node *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}
struct node *InSucc(struct node *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

struct node *Delete(struct node *p, int key)
{
    struct node *q;
    // First check that head == NULL
    if (p == NULL)
        return NULL;
    // Check that key == head->data if it also check that it's left or right are also equal to zero.
    if (p->left == NULL && p->right == NULL)
    {
        if (p == head)
            head = NULL;

        free(p);
        return NULL;
    }
    // Then search for that element
    // else
    // {
    //     while (p->data != key)
    //     {
    //         if (key > p->data)
    //         {
    //             p = p->right;
    //         }
    //         else if (key < p->data)
    //         {
    //             p = p->left;
    //         }
    //     }
    // }

    // if (p->data != key)
    // {
    //     printf("\nElement Not Found \n");
    //     return NULL;
    // }
    if (key < p->data)
        p->left = Delete(p->left, key);
    else if (key > p->data)
        p->right = Delete(p->right, key);
    else
    {
        if (height(p->left) > height(p->right))
        {
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, p->data);
        }
        else
        {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, p->data);
        }
    }
    return p;
}

int main()
{
    Insert(40);
    Insert(20);
    Insert(10);
    Insert(5);
    // Insert(50);
    // Insert(60);
    // Insert(70);
    Delete(head, 40);
    printf("%d\n", head->data);
    printf("%d\n", head->left->data);
    Inorder(head);

    return 0;
}