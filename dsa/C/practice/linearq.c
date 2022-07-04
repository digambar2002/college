#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front, rear = -1;

void enqueue(int item);
void dequeue();
void display();

void enqueue(int item)
{

    if (rear == MAX_SIZE - 1)
    {
        printf("\n Queue is overflow");
    }
    else
    {

        if (front == -1)
        {
            front = 0;
        }

        rear = rear + 1;
        queue[rear] = item;
        printf("\n item %d inserted", item);
    }
}

void display()
{

    if (front == -1 || front > rear)
    {
        printf("\n Queue is empty");
    }
    else
    {

        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void dequeue()
{
    if (front > rear)
    {
        printf("\n Queue is underflow");
    }
    else
    {
        printf("\n item %d deleted", queue[front]);
        front = front + 1;
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();

    return 0;
}
