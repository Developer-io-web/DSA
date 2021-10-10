#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *Create(struct node *head)
{
    struct node *t, *last = NULL;
    int n, i;
    printf("Enter the number of terms : ");
    scanf("%d", &n);

    printf("Enter the coeff and Exponent\n");

    for (i = 0; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        scanf("%d%d", &t->coeff, &t->exp);
        if (head == NULL)
        {
            head = last = t;
            last->next = NULL;
        }
        else
        {
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    return head;
}

void Display(struct node *head)
{
    while (head)
    {
        printf("%dx%d +", head->coeff, head->exp);
        head = head->next;
    }
    printf("\n");
}

long eval(struct node *head, int x)
{
    long val = 0;
    while (head)
    {
        val += (head->coeff * pow(x, head->exp));
        head = head->next;
    }
    return val;
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    head = Create(head);
    Display(head);
    printf("\n%ld", eval(head, 1));
    return 0;
}