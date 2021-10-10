#include <stdio.h>

int main()
{
    //the Two string are said to be anagram if they have the same number of characters and
    // so if two have different size they are not anagram
    char A[] = "decimal";
    char B[] = "medical";
    int heap[26] = {0};
    int i;

    for (i = 0; A[i] != '\0'; i++)
    {
        heap[A[i] - 97]++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        heap[B[i] - 97]--;
        if (heap[B[i] - 97] < 0)
        {
            printf("This is not a anagram");
            break;
        }
    }

    if (B[i] == '\0')
    {
        printf("This is a Anagram");
    }
    return 0;
}