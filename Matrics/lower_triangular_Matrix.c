#include <stdio.h>
#include <stdlib.h>

struct Matric
{
    int *A;
    int n;
};

void set(struct Matric *a, int i, int j, int x)
{
    if (i >= j)
    {
        a->A[(i * (i - 1) / 2) + j - 1] = x;
    }
}

void get(struct Matric a, int i, int j)
{
    if (i >= j)
    {
        printf("%d", a.A[(i * (i - 1) / 2) + j - 1]);
    }
    else
    {
        printf("0");
    }
}

void Display(struct Matric a)
{
    for (int i = 1; i <= a.n; i++)
    {
        for (int j = 1; j <= a.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", a.A[(i * (i - 1) / 2) + j - 1]);
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
    struct Matric mat;
    mat.n = 5;
    int size = mat.n * (mat.n + 1) / 2;
    mat.A = (int *)malloc(size * sizeof(int));

    int x;
    printf("Enter the value\n");
    for (int i = 1; i <= mat.n; i++)
    {

        for (int j = 1; j <= mat.n; j++)
        {
            scanf("%d", &x);
            set(&mat, i, j, x);
        }
    }
    printf("\n\n");

    Display(mat);

    return 0;
}
