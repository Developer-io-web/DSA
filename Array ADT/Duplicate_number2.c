#include <stdio.h>
#define len 10

int main()
{
    int arr[10] = {1, 5, 5, 8, 9, 3, 5, 9, 10, 11};
    int heap[len] = {0};
    for (int i = 0; i < 10; i++)
    {
        heap[arr[i]]++;
    }

    for (int i = 1; i <= 11; i++)
    {
        if (heap[i] > 1)
        {
            printf("The Element is %d and it appears %d times\n ", i, heap[i]);
        }
    }
    return 0;
}