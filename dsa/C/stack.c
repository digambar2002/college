#include <conio.h>
#include <stdio.h>

void push();
void pop();
void display();

int stack[100], i, item, n, ch, top;

void main()
{
    printf("\nEnter the size of the stack: ");
    scanf("%d", &n);
    top = -1;

    do
    {
        printf("\nEnter Choice : ");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nEnter valid choice: ");
            break;
        }
    } while (ch != 4);
}

void push()
{
    if (top >= n - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter the element you want to insert: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top >= 0)
    {
        printf("\nDeleted element is %d ", stack[top]);
        top--;
    }
    else
    {
        printf("\nStack Underflow");
    }
}

void display()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}