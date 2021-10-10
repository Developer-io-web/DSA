#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int num);
    int dequeue();
    void Display();
};

void Queue::enqueue(int num)
{
    if (rear == size - 1)
    {
        printf("The queue is full\n");
    }
    else
    {
        rear++;
        Q[rear] = num;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        printf("The queue is empty\n");
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d ", Q[i]);
    }
}

int main()
{
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.Display();

    return 0;
}