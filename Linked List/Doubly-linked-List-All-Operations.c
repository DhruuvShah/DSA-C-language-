#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void create()
{
    int no, i;
    printf("Enter number of nodes you want to create: ");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insert_begin()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void insert_at_position()
{
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_begin();
        return;
    }
    struct Node *temp = head;
    while (temp && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (!temp)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void traverse()
{
    struct Node *temp = head;
    printf("List (Forward): ");
    while (temp)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_first()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
}

void delete_given_node()
{
    int key;
    printf("Enter data to delete: ");
    scanf("%d", &key);
    struct Node *temp = head;
    while (temp && temp->data != key)
    {
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Node not found\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
}

void delete_last()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}

void count_nodes()
{
    int count = 0;
    struct Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Traverse List\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Given Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            traverse();
            break;
        case 5:
            delete_first();
            break;
        case 6:
            delete_given_node();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            count_nodes();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}