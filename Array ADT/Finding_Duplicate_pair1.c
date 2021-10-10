#include <stdio.h>

int main()
{
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int k = 10, i, j;
    //Method -1
    // for (i = 0; i < 9; i++)
    // {
    //     for (j = i + 1; j < 10; j++)
    //     {
    //         if (arr[i] + arr[j] == k)
    //         {
    //             printf("The %d and %d have sum equal to %d\n", arr[i], arr[j], k);
    //         }
    //     }
    // }

    //Method -2
    int bitset[17] = {0};
    // printf("%d", bitset[-6]);
    for (int i = 0; i < 10; i++)
    {
        int ind = k - arr[i];
        if (ind > 0)
        {
        }
        else
        {
            ind = 0;
        }
        if (bitset[ind] != 0)
        {
            // printf("%d", ind);
            printf("The %d and %d have sum equal to %d\n", arr[i], k - arr[i], k);
        }
        bitset[arr[i]]++;
    }
    return 0;
}