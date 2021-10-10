#include <iostream>
using namespace std;

class hi
{
private:
    int h;

public:
    hi(int h)
    {
        this->h = h;
    };
    void Display();
};

void hi::Display()
{
    cout << h;
}

int main()
{
    hi g(5);
    g.Display();
    return 0;
}