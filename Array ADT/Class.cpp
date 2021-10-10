#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int ind, int num);
    int Delete(int ind);
};

void Array::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}

void Array::Insert(int ind, int num)
{
    if (ind >= 0 && ind <= length)
    {
        for (int i = length; i > ind; i--)
        {
            A[i] = A[i - 1];
        }
        A[ind] = num;
        length++;
    }
}

int Array::Delete(int ind)
{
    int x = 0;
    if (ind >= 0 && ind < length)
    {
        x = A[ind];
        for (int i = ind; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

int main()
{
    class Array arr;

    arr.Insert(0, 1);
    arr.Insert(1, 9);
    arr.Insert(2, 8);
    arr.Display();
    cout << arr.Delete(0) << "       ";
    arr.Display();
    return 0;
}