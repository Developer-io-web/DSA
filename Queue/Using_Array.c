#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
} *q = NULL;

void Create()
{
    q = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the Size of the Array ");
    scanf("%d", &q->size);
    q->Q = (int *)malloc(q->size * sizeof(int));

    q->front = q->rear = -1;
}

void enqueue(int num)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = num;
    }
}

int dequeue()
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
}

void Display()
{
    int i;
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->Q[i]);
    }
}

int main()
{
    Create();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    Display();
    return 0;
}