#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *S;
};

void Push(struct stack *st, int num)
{
    if (st->top == st->size - 1)
    {
        printf("Overflow");
    }
    else
    {
        st->top++;
        st->S[st->top] = num;
    }
}

void Display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d", st.S[i]);
        printf("\n");
    }
}

int Pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Underflow");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct stack st, int ind)
{
    if (st.top - ind + 1 < 0)
    {
        printf("Invalid Position");
        return -1;
    }
    else
    {
        return st.S[st.top - ind + 1];
    }
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
    {
        return 0;
    }
    return 1;
}
int stackTop(struct stack st)
{
    if (isEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}

int isFull(struct stack st)
{
    if (st.top == st.size - 1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    struct stack *st;
    printf("Enter the size of the Stack : ");
    scanf("%d", &st->size);
    st->S = (int *)malloc(st->size * sizeof(int));
    st->top = -1;

    Push(st, 10);
    Push(st, 20);
    Push(st, 30);

    // Pop(st);
    // Pop(st);
    // Pop(st);
    // Pop(st);
    printf("%d", stackTop(*st));

    // Display(*st);

    return 0;
}