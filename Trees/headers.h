#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct Queue
{
    int size;
    struct node **Q;
    int front;
    int rear;
};

void create(struct Queue *q)
{
    printf("Enter the size of the queue: ");
    scanf("%d", &(q->size));
    q->front = q->rear = 0;

    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}

void enqueue(struct Queue *q, struct node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("The Queue is FULL");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct node *dequeue(struct Queue *q)
{
    struct node *x = NULL;
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
