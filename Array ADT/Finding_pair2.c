#include <stdio.h>

int main()
{
    // For Sorted
    int A[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int i = 0, j = 9, k = 10;
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            printf("The Sum of %d and %d is %d\n", A[i], A[j], k);
            i++;
            j--;
        }
        else if (A[i] + A[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}