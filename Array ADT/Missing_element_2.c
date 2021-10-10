#include <stdio.h>
#define h 13
//We have make a array and initailaized it with 0 and increase the value by 1 when we encounter an element of that index.
int main()
{
    int arr[9] = {2, 7, 9, 12, 1, 6, 5, 10};
    int l = 1;
    int Find[h] = {0}; // Here we cannot do Find[h] coz at compile time it is unable to compile.
    for (int i = 0; i <= 9; i++)
    {
        Find[arr[i]]++;
    }

    for (l; l < h; l++)
    {
        if (Find[l] == 0)
        {
            printf("The Missing Element is : %d\n", l);
        }
    }
    return 0;
}