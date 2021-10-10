#include <stdio.h>

struct matrics
{
    int A[10];
    int n; // This will store the size of the matrix;
};

void set(struct matrics *max, int i, int j, int x)
{
    if (i == j)
    {
        max->A[i - 1] = x;
    }
}

void get(struct matrics max, int i, int j)
{
    if (i == j)
    {
        printf("%d \n", max.A[i - 1]);
    }
    else
    {
        printf("%d\n", 0);
    }
}

void display(struct matrics max)
{
    for (int i = 0; i < max.n; i++)
    {
        for (int j = 0; j < max.n; j++)
        {
            if (i == j)
            {
                printf("%d ", max.A[i]);
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main()
{
    struct matrics max;
    max.n = 4;
    set(&max, 1, 1, 6);
    set(&max, 2, 2, 7);
    set(&max, 3, 3, 4);
    set(&max, 4, 4, 5);
    get(max, 2, 2);
    display(max);
    return 0;
}