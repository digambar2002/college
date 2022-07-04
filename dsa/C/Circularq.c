// NIKITA SUNIL PATIL SE B 32
// Program to implement Circular Queue using Array

#include <stdio.h>
#include <stdlib.h>

#define max 50

void insert();
void delete ();
void display();
int queue[max];
int rear = -1;
int front = -1;
void main()
{
    int ch;
    printf("\nOperations on Circular Queue");
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
    int element;
    printf("\nEnter the element to be inserted in the queue");
    scanf("%d", &element);
    if (front == -1 && rear == -1) // condition to check queue is empty
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front) // condition to check queue is full
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % max; // rear is incremented
        queue[rear] = element;   // assigning a value to the queue at the rear position.
    }
}

void delete ()
{
    if ((front == -1) && (rear == -1)) // condition to check queue is empty
    {
        printf("\nQueue is underflow..");
    }
    else if (front == rear) // there is only one element into the queue
    {
        printf("\nThe deleted element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe deleted element is %d", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        for (i = front; i <= rear; i++)

            printf("%d ", queue[i]);
        printf("\nFront = %d, Rear = %d", front, rear);
        printf("\n");
    }
}