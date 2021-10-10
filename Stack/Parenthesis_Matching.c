#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void push(char num)
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

char pop()
{
    struct node *t = top;
    char x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
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
        printf("%c ", top->data);
        top = top->next;
    }
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "((a+b)*(c-d))";
    printf("%d", isBalanced(exp));

    // Display();

    return 0;
}