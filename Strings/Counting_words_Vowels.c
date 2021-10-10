#include <stdio.h>

int main()
{

    //Counting Vowels and consonants
    char A[] = "How are   you";
    int vcount = 0, ccount = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if ((A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') || (A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U'))
        {
            vcount++;
        }
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
        {
            ccount++;
        }
    }
    // printf("The total number of vowel and consonants are %d and %d", vcount, ccount);

    //Counting the Numbeer of Words
    int space = 0; // Words are 1 more than the Spaces.
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
        {
            space++;
        }
    }

    printf("The total number of Words are %d", space + 1);
    return 0;
}