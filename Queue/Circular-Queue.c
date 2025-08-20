#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        printf("Overflow condition\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d was enqueued to circular queue\n", value);
    }
}

int dequeue()
{
    int variable;

    if (front == -1)
    {
        printf("Underflow condition\n");
        return -1;
    }
    else
    {
        variable = queue[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }

        printf("%d was dequeued from circular queue\n", variable);
        return 1;
    }
}

void print()
{
    int i;

    if (front == -1)
        printf("Nothing to delete\n");
    else
    {
        printf("\nThe queue looks like: \n");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d \n\n", queue[i]);
    }
}

int main()
{
    dequeue();

    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);
    enqueue(35);

    print();

    dequeue();
    dequeue();

    print();

    enqueue(40);
    enqueue(45);
    enqueue(50);
    enqueue(55);

    print();

    return 0;
}