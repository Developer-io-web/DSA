#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    void get(int i, int j);
    void Display();
};

void Diagonal::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

void Diagonal::get(int i, int j)
{
    if (i == j)
    {
        // printf("%d\n",A[i-1]);
        cout << A[i - 1] << "\n";
    }
    else
    {
        // printf("%d\n",0);
        cout << 0 << "\n";
    }
}

void Diagonal::Display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                // printf("%d ",A[i]);
                cout << A[i] << " ";
            }
            else
            {
                // printf("%d ",0);
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    Diagonal d(4);
    d.set(1, 1, 4);
    d.set(2, 2, 8);
    d.set(3, 3, 2);
    d.set(4, 4, 9);
    d.get(2, 3);
    d.Display();

    return 0;
}