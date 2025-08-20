#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value);
void pop();
void display();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            while (top != NULL)
            {
                pop();
            }
            exit(0);
        default:
            printf("Invalid choice. Please select a valid option (1-4).\n");
        }
    }

    return 0;
}

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow: Cannot allocate memory.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack\n", value);
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow: The stack is empty.\n");
        return;
    }

    temp = top;

    printf("%d popped from stack\n", temp->data);

    top = top->next;

    free(temp);
}

void display()
{
    struct Node *temp = top;

    if (temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (from top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
