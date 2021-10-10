#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct element *arr;
};

void create(struct sparse *s)
{
    int i;
    printf("Enter the dimensions ");
    scanf("%d %d", &s->m, &s->n);

    printf("Enter the number of non-zero elemnts");
    scanf("%d", &s->num);

    s->arr = (struct element *)malloc(s->num * sizeof(struct element));

    printf("Enter the Elements");
    for (i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->arr[i].i, &s->arr[i].j, &s->arr[i].x);
    }
}

void Display(struct sparse s)
{
    int i, j, k = 0;

    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.arr[k].i && j == s.arr[k].j)
            {
                printf("%d ", s.arr[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    struct sparse *s3;
    s3 = (struct sparse *)malloc(sizeof(struct sparse));
    s3->arr = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));

    int i, j, k;
    i = j = k = 0;
    while (i < s1->num && j < s2->num)
    {
        if (s1->arr[i].i < s2->arr[j].i)
        {
            s3->arr[k++] = s1->arr[i++];
        }
        else if (s1->arr[i].i > s2->arr[j].i)
        {
            s3->arr[k++] = s2->arr[j++];
        }
        else
        {
            if (s1->arr[i].j < s2->arr[j].j)
            {
                s3->arr[k++] = s1->arr[i++];
            }
            else if (s1->arr[i].j > s2->arr[j].j)
            {
                s3->arr[k++] = s2->arr[j++];
            }
            else
            {
                s3->arr[k] = s1->arr[i];
                s3->arr[k++].x = s1->arr[i++].x + s2->arr[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
    {
        s3->arr[k++] = s1->arr[i];
    }
    for (; j < s2->num; j++)
    {
        s3->arr[k++] = s1->arr[j];
    }

    s3->m = s1->m;
    s3->n = s1->n;
    s3->num = k;
    return s3;
}

int main()
{
    struct sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1, &s2);
    printf("matrix 1\n\n");
    Display(s1);
    printf("matrix 2\n\n");
    Display(s2);
    printf("matrix 3\n\n");
    Display(*s3);

    return 0;
}
