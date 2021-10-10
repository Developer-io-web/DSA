#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Insert(struct Array *arr, int ind, int val)
{
    if (ind >= 0 && ind <= arr->length)
    {
        for (int i = arr->length; i >= ind; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->length++;
        arr->A[ind] = val;
    }
}

void Append(struct Array *arr, int value)
{
    arr->A[arr->length] = value;
    arr->length++;
}

int Delete(struct Array *arr, int ind)
{
    int x;
    if (ind >= 0 && ind < arr->length)
    {
        x = arr->A[ind];
        for (int i = ind; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return -1;
}

int main()
{
    int n;

    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    // printf("Enter the Size of the Array : ");
    // scanf("%d", &arr.size);

    // arr.A = (int *)malloc(arr.size * sizeof(int));

    // printf("Enter the Number of the Element you want to enter  : ");
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr.A[i]);
    // }

    // arr.length = n;
    Append(&arr, 10);
    // Insert(&arr, 1, 9);
    printf("Before Deletion");
    Display(arr);

    printf("After Deletion");
    Delete(&arr, 0);
    Display(arr);

    return 0;
}