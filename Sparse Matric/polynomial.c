#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int coeff;
    int ras;
};

struct polynomial
{
    int n;
    struct Element *arr;
};

void Create(struct polynomial *p)
{
    printf("Enter the total Element");
    scanf("%d", &p->n);
    p->arr = (struct Element *)malloc(p->n * sizeof(struct Element));
    printf("Enter the Elements");
    for (int i = 0; i < p->n; i++)
    {
        printf("Enter the %d  ", i + 1);
        scanf("%d %d", &p->arr[i].coeff, &p->arr[i].ras);
    }
}

void Display(struct polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%d %d\n", p.arr[i].coeff, p.arr[i].ras);
    }
}

int main()
{
    struct polynomial p;
    Create(&p);
    Display(p);

    return 0;
}