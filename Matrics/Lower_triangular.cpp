#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix()
    {
        n = 5;
        A = new int[n * (n + 1) / 2];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~Matrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    void get(int i, int j);
    void Display();
    // void Display();
};

void Matrix::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[(i * (i - 1) / 2) + j - 1] = x;
    }
}

void Matrix::get(int i, int j)
{
    if (i >= j)
    {
        cout << A[(i * (i - 1) / 2) + j - 1] << "\n";
    }
    else
    {
        cout << "0";
    }
}

void Matrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[(i * (i - 1) / 2) + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    Matrix d[5];
    // d->Display();
    int x;
    cout << "Enter the value\n"
         << endl;
    for (int i = 1; i <= 5; i++)
    {

        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &x);
            d->Set(i, j, x);
        }
    }
    printf("\n\n");
    3 d->Display();

    return 0;
}