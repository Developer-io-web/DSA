#include <stdio.h>

int main()
{
    //Using Bitwise Operation
    char A[] = "jayanant";
    long int h = 0, s = 0; //LOng int have a size of 4 bytes and therefore uses 36 bits but we need only 26 bits
    for (int i = 0; A[i] != '\0'; i++)
    {
        s = 1; // this is supplementry int which helps us to find that at that index there is a element  already .
        s = s << A[i] - 97;
        if ((h & s) > 0) //masking checking if it appers once
        {
            printf("The %c is a Duplicate\n", A[i]); //Not able to find out the number of time .
        }
        else
        {
            h = h | s; // In this we are setting that equal to 1;
        }
    }
    return 0;
}