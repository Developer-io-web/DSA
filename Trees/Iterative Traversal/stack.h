#include <stdio.h>
#include <stdlib.h>

// struct node
// {
//     struct node *lchild;
//     int data;
//     struct node *rchild;
// };

struct Stack
{
    int top;
    int size;
    struct node **S;
};

void Stackcreate(struct Stack *s, int num)
{
    s->size = num;
    s->S = (struct node **)malloc(s->size * sizeof(struct node *));
    s->top = -1;
}

void push(struct Stack *s, struct node *n)
{
    if (s->top == s->size - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        s->top++;
        s->S[s->top] = n;
    }
}

struct node *pop(struct Stack *s)
{
    struct node *x = NULL;
    if (s->top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        x = s->S[s->top];
        s->top--;
    }
    return x;
}

int isEmpty(struct Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}
