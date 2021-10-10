#include <stdio.h>

int main()
{
    // Method -1
    char a[] = "nitih";
    char b[6];
    //Reversing the string into b
    int i, j;
    for (i = 0; i < 5; i++)
    {
    }
    i--;
    for (j = 0; j < 5; j++, i--)
    {
        b[j] = a[i];
    }
    b[j] = '\0';
    // printf("%s\n", b);
    for (i = 0, j = 0; a[i] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    // if (a[i] == b[j])
    // {
    //     printf("They are palindrome");
    // }
    // else
    // {
    //     printf("They are not palindrome");
    // }

    //Method -2
    int flag = 1;
    for (j = 0; a[j] != '\0'; j++)
    {
    }
    j--;
    i = 0;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if (a[i] != a[j])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("The string is a palindrome");
    }
    else
    {
        printf("The string is not palindrome");
    }

    return 0;
}