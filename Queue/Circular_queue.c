#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
} *q = NULL;

void create()
{
    q = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the Array Size ");
    scanf("%d", &q->size);

    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(int num)
{
    // Checks if it is Full or not.
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = num;
    }
}

int dequeue()
{
    int x = -1;
    //Checks that Array is Empty or not.
    if (q->rear == q->front)
    {
        printf("Queue is Empty");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display()
{
    int i = q->front + 1;
    do
    {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    } while (i != (q->rear + 1) % q->size);
}

int main()
{
    create(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    Display();

    return 0;
}