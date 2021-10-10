#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int num);
    int pop();
    void Display();
};

void Stack::push(int num)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        t->data = num;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x;
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Node *t = new Node;
        x = top->data;
        t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *t = top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int main()
{
    Stack str;
    str.push(10);
    str.push(30);
    str.push(20);
    cout << str.pop();
    str.Display();
    return 0;
}