#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

int findMissingNumber(struct Array arr)
{
    int l, h, sum, s = 0;
    l = 0;
    h = arr.length - 1;
    sum = 0;
    for (int i = 0; i <= h; i++)
    {
        sum = sum + arr.A[i];
    }
    int n = arr.A[h];
    s = n * (n + 1) / 2;

    // printf("%d %d %d", sum, n, s);
    int diff = s - sum;
    return diff;
}

int main()
{
    // struct Array arr = {{1, 2, 3, 4, 6, 7, 8, 9}, 8, 10};
    // struct Array arr = {{6, 7, 8, 9, 10, 12, 13, 14, 15}, 8, 10};
    // findMissingNumber(arr);
    // printf("%d", findMissingNumber(arr));

    //Approach - 2
    int arr[6] = {3, 4, 5, 9, 10, 12};

    int count = arr[0];
    for (int i = 1; i < 6; i++)
    {
        ++count;
        while (count != arr[i])
        {
            printf("The Missing Element is %d\n", count);
            ++count;
            // if (count != arr[i])
            // {
            //     printf("The Other Missing element is %d", count);
            //     count++;
            // }
        }
    }
    return 0;
}
