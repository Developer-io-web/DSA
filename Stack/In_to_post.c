#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Stack is Full");
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

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    return 0;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

char *inToPost(char *infix)
{
    int len = strlen(infix) + 1;
    char *postfix = (char *)malloc(len + 1 * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c/d";
    char *postfix;
    push('#');
    postfix = inToPost(infix);
    printf("%s\n", postfix);

    return 0;
}