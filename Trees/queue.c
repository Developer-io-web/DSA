#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int *Q;
    int front;
    int rear;
} *q = NULL;

void create()
{
    q = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the size of the queue: ");
    scanf("%d", &(q->size));
    q->front = q->rear = 0;

    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(int num)
{
    if (q->Q[(q->rear + 1) % q->size] == q->Q[q->front])
    {
        printf("The Queue is FULL");
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
    if (q->front == q->rear)
    {
        printf("The Queue is Empty");
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
    create();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("The DELETED Element is :%d\n", dequeue());
    printf("The DELETED Element is :%d\n", dequeue());
    enqueue(70);
    Display();

    return 0;
}