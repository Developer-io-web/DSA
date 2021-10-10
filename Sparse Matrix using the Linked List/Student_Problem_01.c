//We have to Create a Sparse Matrix using the Linked list.
// We have to only store the non-zero elements In the linked list .
// Display
// Add two sparse matrix

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int col;
    int val;
    struct node *next;
};

int main()
{
    int m = 5, n = 6;
    struct node *A[5], *t, *last;
    int i, j, flag = 0;
    for (i = 0; i < m; i++)
    {
        printf("\n\nRow %d\n", i);
        int col, val;
        A[i] = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coln and the value \n");
        scanf("%d %d", &col, &val);
        A[i]->col = col;
        A[i]->val = val;
        A[i]->next = NULL;
        last = A[i];
        printf("Do you want to enter More In the same Row 1/0 ");
        scanf("%d", &flag);
        while (flag)
        {
            int col, val;
            t = (struct node *)malloc(sizeof(struct node));
            printf("Enter the coln and the value \n");
            scanf("%d %d", &col, &val);
            t->col = col;
            t->val = val;
            t->next = NULL;
            last->next = t;
            last = t;
            printf("Do you want to enter More In the same Row 1/0 ");
            scanf("%d", &flag);
        }
    }
    struct node *p;
    for (i = 0; i < m; i++)
    {
        p = A[i];
        for (j = 0; j < n; j++)
        {
            if (p && j == p->col)
            {
                printf("%d ", p->val);
                p = p->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
