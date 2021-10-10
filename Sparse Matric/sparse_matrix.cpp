#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class sparse_Matrix
{
private:
    int m;
    int n;
    int num;
    Element *arr;

public:
    sparse_Matrix(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        arr = new Element[this->num];
    }
    ~sparse_Matrix()
    {
        delete[] arr;
    }
    void read()
    {
        cout << "Enter the non-zero Elements" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i].i >> arr[i].j >> arr[i].x;
        }
    }
    void Display()
    {
        int i, j, k = 0;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == arr[k].i && j == arr[k].j)
                {
                    cout << arr[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    sparse_Matrix s(5, 5, 5);
    s.read();
    s.Display();

    return 0;
}