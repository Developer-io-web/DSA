#include <stdio.h>

int main()
{
    //Change to Uppercase
    // char s[] = "MONU";
    // for (int i = 0; s[i] != '\0'; i++)
    // {
    //     s[i] = s[i] + 32;
    // }
    // printf("%s", s);

    //From Upper to lower and vice versa also.
    char A[] = "jkdkdfddsjl0";
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A[i] += 32;
        }
        else if (A[i] >= 'a' && A[i] <= 'z')
        {
            A[i] -= 32;
        }
    }
    printf("%s", A);
    return 0;
}