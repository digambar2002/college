#include <stdio.h>
#include <conio.h>

int stack[100], ch, n, top, item, i;

void push(int item);
void pop();
void display();

void push(int item)
{

    if (top >= n - 1)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("item %d push \n", item);
    }
}

void display()
{

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}

void pop()
{

    if (top >= 0)
    {
        printf("item %d deleted \n", stack[top]);
        top--;
    }
    else
    {
        printf("Stack underdlow \n");
    }
}

int main()
{
    top = -1;
    n = 5;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}
