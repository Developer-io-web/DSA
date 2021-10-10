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

int leftShift(struct Array *arr)
{
    for (int i = 1; i < arr->length; i++)
    {
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = 0;
}
int rightShift(struct Array *arr)
{
    for (int i = arr->length - 2; i >= 0; i--)
    {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[0] = 0;
}

int main()
{
    struct Array arr =
        {
            {1, 2, 3, 4, 5, 6, 7}, 7, 10};

    // leftShift(&arr);
    rightShift(&arr);
    Display(arr);

    return 0;
}