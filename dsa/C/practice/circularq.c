#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int item);
void delete ();
void display();

void insert(int item)
{

    // Only Once execute
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = item;
        printf("\n Item %d Inserted", item);
    }
    else if ((rear + 1) % MAX_SIZE == front)
    {
        printf("\n Queue is full");
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("\n Item %d Inserted", item);
    }
}

void delete ()
{

    // Check Queue is empty or not
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }

    // if only one element in queue in this run
    else if (front == rear)
    {
        printf("\n Item %d deleted", queue[front]);
        front = rear = -1;
    }
    // Delete element by incrementing front
    else
    {

        printf("\n Item %d deleted", queue[front]);
        front = (front + 1) % MAX_SIZE;
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
        for (i = 0; i <= MAX_SIZE - 1; i++)
        {

            printf("%d ", queue[i]);
        }

        printf("\nFront = %d, Rear = %d", front, rear);
        printf("\n");
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    delete ();
    delete ();

    display();

    insert(60);
    insert(70);

    display();

    delete ();
    delete ();
    delete ();

    display();

    insert(80);
    insert(90);

    display();
    delete ();
    display();

    return 0;
}
