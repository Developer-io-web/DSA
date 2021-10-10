#include <iostream>
using namespace std;

class Stack
{
private:
    int *S;
    int top;
    int size;

public:
    Stack()
    {
        top = -1;
        size = 5;
        S = new int[size];
    }
    Stack(int size)
    {
        this->size = size;
        top = -1;
        S = new int[size];
    }
    ~Stack()
    {
        delete[] S;
    }
    void push(int num);
    void Display();
    int peek(int pos);
    int isEmpty();
    int isFull();
    int stackTop();
};

void Stack::push(int num)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        S[top] = num;
    }
}

void Stack::Display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}
int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int Stack::peek(int pos)
{
    if (top - pos + 1 >= 0)
    {
        return S[top - pos + 1];
    }
    return -1;
}

int Stack::StackTop

    int
    main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    st.Display();

    return 0;
}