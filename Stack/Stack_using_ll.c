#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void Push(int num)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        t->data = num;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct node *t = top;
    int x;
    if (top == NULL)
    {
        printf("The Stack Is Empty");
    }
    else
    {
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    while (top)
    {
        printf("%d ", top->data);
        top = top->next;
    }
}

int stackTop()
{
    if (top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        return top->data;
    }
    return -1;
}

int peek(int ind)
{
    struct node *p = top;
    int i;
    for (i = 0; i < ind - 1; i++)
    {
        p = p->next;
    }
    return p->data;
}

int isEmpty()
{
    int r = top ? 0 : 1;
    return r;
}

int isFull()
{
    struct node *p;
    int r = p ? 0 : 1;
    return r;
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    pop();
    pop();
    pop();
    // printf("%d", peek(2));
    printf("%d", isEmpty());
    // Display();
    return 0;
}