#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(char num)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Stack overflow");
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
    char x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        struct node *p = top;
        x = p->data;
        top = top->next;
        free(p);
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

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == ')' || x == '(' || x == '^')
    {
        return 0;
    }
    return 1;
}

int Outpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int Inpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

char *InToPost(char *infix)
{
    int len = strlen(infix) + 2;
    char *postfix = (char *)malloc(len * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (Outpre(infix[i]) > Inpre(top->data))
            {
                push(infix[i++]);
            }
            else if (Outpre(infix[i]) == Inpre(top->data))
            {
                pop();
                i++;
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    char *postfix;
    push('#');
    postfix = InToPost(infix);
    printf("%s\n", postfix);
    return 0;
}