#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LSearch(struct Array *arr, int n)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == n)
        {
            Swap(&arr->A[i], &arr->A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7}, 10, 7};

    printf("%d", LSearch(&arr, 9));
    printf("\n");
    Display(arr);

    return 0;
}