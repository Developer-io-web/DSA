#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

int Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}

int Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse(struct Array *arr)
{
    int *b;
    int i, j;
    b = (int *)malloc(sizeof(int) * arr->length);

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = b[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6, 7}, 7, 10};

    Display(arr);
    printf("\n");
    printf("After Revesing :\n");

    Reverse2(&arr);
    Display(arr);

    return 0;
}