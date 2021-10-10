#include <stdio.h>

int main()
{
    char a[] = "pyhton";
    char b[] = "pyhton1";

    int i, j;
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; j++, i++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
    {
        printf("The Strings are equal");
    }
    else if (a[i] > b[j])
    {
        printf("The A is larger than the b");
    }
    else
    {
        printf("The B is larger than the A");
    }
    return 0;
}