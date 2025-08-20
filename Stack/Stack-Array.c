#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int value)
{
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void peek()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top Element: %d\n", stack[top]);
}

void display()
{
    int i;
    if (top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack Elements: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void main()
{
    int choice, value;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 5);
}
