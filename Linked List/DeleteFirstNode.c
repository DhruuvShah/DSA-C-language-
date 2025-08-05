#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteFirstNode(struct Node **start)
{
    struct Node *ptr;

    if (*start == NULL)
    {
        printf("LIst is empty\n");
        return;
    }

    ptr = *start;
    *start = (*start)->next;
    free(ptr);
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createSampleList(struct Node **start)
{
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    *start = n1;
}

int main()
{
    struct Node * start = NULL;

    createSampleList(&start);
    printf("Original List\n");
    display(start);

    deleteFirstNode(&start);
    printf("\nAfter deleting the first node\n");
    display(start);
    return 0;
}