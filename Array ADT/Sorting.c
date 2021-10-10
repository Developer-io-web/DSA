#include <stdio.h>

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
        printf("%d ", arr.A[i]);
    }
}

int Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(struct Array *arr, int x)
{
    int n = arr->length - 1;
    while (n >= 0 && arr->A[n] > x)
    {
        arr->A[n + 1] = arr->A[n];
        n--;
    }
    arr->A[n + 1] = x;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Arrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j++;
        }
        Swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{-2, 1, -44, 78, 88, -90}, 6, 10};
    // InsertSort(&arr, 1);
    // printf("%d", isSorted(arr));
    Arrange(&arr);
    // Display(arr);
    return 0;
}