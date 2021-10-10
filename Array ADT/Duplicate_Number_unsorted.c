#include <stdio.h>

int main()
{
    int count;
    int arr[10] = {5, 72, 9, 5, 8, 9, 4, 13, 9};
    for (int i = 0; i < 9; i++)
    {
        count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            printf("%d number appears %d times\n", arr[i], count);
        }
    }
    return 0;
}