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
    char x;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        x = top->data;
        top = top->next;
        free(t);
    }
    return x;
}

void Display()
{
    while (top)
    {
        printf("%d", top->data);
        top = top->next;
    }
}

int isBalanced(char *exp)
{
    int i;
    char x;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            x = pop();
            int diff = exp[i] - x;
            // printf("%c and %c", exp[i], x);
            if (diff <= 2)
            {
                if ((x == '(' && exp[i] == ')') || (x == '[' && exp[i] == ']') || (x == '{' && exp[i] == '}'))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
}

int main()
{
    char *exp = "{(a+b)*[a+b]}";
    printf("%d", isBalanced(exp));
    return 0;
}