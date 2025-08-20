#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
        newNode->next = NULL;
        if (!head)
            head = newNode;
        else
        {
            struct Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insert_begin()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
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
    temp->next = newNode;
}

void traverse()
{
    struct Node *temp = head;
    printf("List: ");
    while (temp)
    {
        printf("%d -> ", temp->data);
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
    free(temp);
}

void delete_given_node()
{
    int key;
    printf("Enter data to delete: ");
    scanf("%d", &key);
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void delete_last()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
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
        printf("\n--- Singly Linked List Menu ---\n");
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