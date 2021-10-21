#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
    node *lchild; // It is made public coz it will be easily accessible in other classes.
    int data;
    node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    node **Q;
    int size;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new node *[size];
    }
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new node *[size];
    }
    void enqueue(node *num);
    node *dequeue();
    int isEmpty() { return front == rear; }
};

void Queue::enqueue(node *num)
{
    if (front == size - 1)
    {
        printf("The Queue is FULL");
    }
    else
    {
        rear++;
        Q[rear] = num;
    }
}

node *Queue::dequeue()
{
    node *x = NULL;
    if (front == rear)
    {
        printf("The queue is Empty");
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
