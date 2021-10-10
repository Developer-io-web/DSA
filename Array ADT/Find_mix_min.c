#include <stdio.h>

int main()
{
    int arr[9] = {5, 72, 9, 5, 8, 9, 4, 13, 9};
    int min = arr[0], max = arr[0];

    for (int i = 1; i < 9; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("The max and min numbers are %d,%d", max, min);
    return 0;
}