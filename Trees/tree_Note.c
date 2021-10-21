
----------using c ------------------
So the idea is that we make the root node first,insert the value in it and assign it's left and right by NULL.

//  head = (struct node *)malloc(sizeof(struct node));
//     head->data = x;
//     head->lchild = NULL;
//     head->rchild = NULL;

so after that we insert the address of the head/root node into the Queue.

1.) For this we make a Queue => Structure Either Circular or Normal.
2.) After that we ask remove the eleemnts from the queue one by one and assign them to pointer p.

      //   p = dequeue(&q);   q here is the Queue

3.) After then we ask for the user to input the left node value and assigns its values to also NULL and also point the p->left to the t. 

//  t = (struct node *)malloc(sizeof(struct node));
//         printf("Enter the value of Left child of %d", p->data);
//         scanf("%d", &x);
//             t->data = x;
//             t->lchild = NULL;
//             t->rchild = NULL;
//             p->lchild = t;
//             enqueue(&q, t);

**Repeats the same steps for the Right part also**

4.)  We do this until the queue become Empty.


** if the user inputs -1 that's means he don't want to enter the things.

***********************************************


**Making your own Header Files and Using it**

- Make a file with .h extension with main function Excluded
- Use that in the Code like =>

//          #include"sample.h"



************************************************


** Using a Queue for the insertion of the Address of the struct node * type variable

- So to store that value the Queue must be of the same type
- And also we have to make a charactre pointer to Array so one star for that.

            // struct Queue
            // {
            //     int size;
            //     struct node **Q;
            //     int front;
            //     int rear;
            // };

            -- Here the Node is Tree structure i.e lchild,data,rchild

- So in the Enqueue the argument must be of struct node * type 
- IN Dequeue it's type must be  of struct node *type and the type of x should be same also.