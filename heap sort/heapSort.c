#include <stdio.h>

void Insert(int *A, int n)
{
    int temp = A[n]; // Here n represnts the index of element which we want to Insert.
    int i = n;
    while (i > 1 && temp > A[i / 2])
    { // Here A[i/2] represents the Parent Element of the child if the child is greater the parent then we should swap.
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int *A, int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }
        if (A[j] > A[i])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return val;
}

int main()
{
    // Max Heap
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for (int i = 2; i <= 7; i++)
    {
        Insert(A, i);
    }

    for (int i = 7; i > 1; i--)
    {
        Delete(A, i);
    }

    for (int i = 0; i <= 7; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}