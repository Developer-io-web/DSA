#include <stdio.h>

int main()
{
    char A[] = "jayaannt";
    int i, j, count;
    // int n = 8;
    // // method - 1
    // for (i = 0; i < 7; i++)
    // {
    //     count = 0;
    //     for (j = i + 1; j < 8; j++)
    //     {
    //         if (A[i] == A[j] && A[i] != -1)
    //         {
    //             count++;
    //             A[j] = -1;
    //         }
    //     }
    // if (count > 0)
    // {
    //     printf("The %c appears %d times\n", A[i], count);
    // }

    // Method - 2
    int heap[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
    {
        heap[A[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
    {
        if (heap[i] > 1)
        {
            printf("The %c appears %d times \n", i + 97, heap[i]);
        }
    }

    return 0;
}