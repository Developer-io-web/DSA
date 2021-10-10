#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int num)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Stack is Full");
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
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty");
    else
    {
        struct node *p = top;
        top = top->next;
        x = p->data;
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
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int Eval(char *postfix)
{
    int i = 0;
    int x1, x2, res;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            int x2 = pop();
            int x1 = pop();
            switch (postfix[i])
            {
            case '+':
                res = x1 + x2;
                break;
            case '-':
                res = x1 - x2;
                break;
            case '/':
                res = x1 / x2;
                break;
            case '*':
                res = x1 * x2;
                break;
            }
            push(res);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result is %d\n", Eval(postfix));
    return 0;
}
