#include <stdio.h>
#include <stdlib.h>

// struct node
// {
//     long intlchild;
//     int data;
//     long intrchild;
// };

struct Stack
{
    int top;
    int size;
    long int *S;
};

void Stackcreate(struct Stack *s, int num)
{
    s->size = num;
    s->S = (long int *)malloc(s->size * sizeof(long int));
    s->top = -1;
}

void push(struct Stack *s, long int n)
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

long int pop(struct Stack *s)
{
    long int x = 0;
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
