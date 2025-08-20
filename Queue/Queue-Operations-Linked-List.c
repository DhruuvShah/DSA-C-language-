#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("%d removed from queue\n", temp->data);
    free(temp);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void peek()
{
    if (front == NULL)
        printf("Queue is empty\n");
    else
        printf("Front element is: %d\n", front->data);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    peek();

    return 0;
}