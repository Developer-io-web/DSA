#include <stdio.h>

int main()
{
    // Displaying the Duplicate numbers [If number is appearing more than 2 times then also we have to print it only once]
    //For the Sorted Array

    // int arr[7] = {1, 2, 2, 6, 8, 8, 8};
    // int lastDuplicate;

    // for (int i = 0; i < 6; i++)
    // {
    //     if (arr[i] == arr[i + 1])
    //     {
    //         if (lastDuplicate != arr[i])
    //         {
    //             printf("Duplicate Number is : %d\n", arr[i]);
    //         }
    //         lastDuplicate = arr[i];
    //     }
    // }
    //Displaying the Duplicates + Counting the Number of time they Appears.
    int arr[7] = {1, 2, 2, 6, 8, 8, 8};
    int j;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[j] == arr[i])
            {
                j++;
            }
            printf("Duplicate Number is %d , and it appears %d\n", arr[i], j - i);
            i = j - 1;
        }
    }

    return 0;
}