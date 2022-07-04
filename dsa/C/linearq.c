// nikita sunil patil se b 32
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void insert();
void delete ();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
void main()
{
    int ch;
    printf("\nOperations on Linear Queue");
    printf("\n1. Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n4.Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid choice");
        }
    } while (ch != 4);
}
void insert()
{
    int add_item;        // value to be inserted
    if (rear == MAX - 1) // Queue full condition
    {
        printf("Queue Overflow \n");
    }

    else
    {
        if (front == -1) // Inserting first element
        {
            front = 0;
        }

        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1; // rear = 0
        queue_array[rear] = add_item;
    }
}

void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty \n");
    }

    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)

            printf("%d ", queue_array[i]);
        printf("\nFront = %d, Rear = %d", front, rear);
        printf("\n");
    }
}