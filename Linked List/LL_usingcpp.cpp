#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class LL
{
private:
    node *head;

public:
    LL()
    {
        head = NULL;
    }
    LL(int *A, int n);
    // ~LL();

    void Display();
};

LL::LL(int *A, int n)
{
    node *last, *t;
    head = new node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LL::Display()
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LL l(A, 5);
    l.Display();

    return 0;
}