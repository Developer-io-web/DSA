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

int BinarySearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (key > arr.A[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key > arr.A[mid])
        {
            return RBinaryS + 1, hearch(arr, mid, key);
        }
        else
        {
            return RBinarySearch(arr, l, mid - 1, key);
        }
    }
    return -1;
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 10};

    printf("%d", RBinarySearch(arr, 0, 8, 15));

    return 0;
}