#include <stdio.h>

int main()
{
    // char arr[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};
    char arr[] = "python";
    char store[7];
    int i, j;
    for (i = 0; arr[i] != '\0'; i++)
    {
    }
    i--;
    for (j = 0; j < 6; j++, i--)
    {
        store[j] = arr[i];
    }
    store[j] = '\0';

    printf("Using Method -1 %s \n", store);

    //Method -2
    int temp;
    for (i = 0; arr[i] != '\0'; i++)
    {
    }
    i--;
    for (j = 0; i > j; i--, j++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("Using Method - 2 %s ", arr);

    return 0;
}