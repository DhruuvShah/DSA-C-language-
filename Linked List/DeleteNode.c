#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node with a given value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    // Search for the node with the given key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // If node is head
    if (temp->prev == NULL) {
        *head_ref = temp->next;
        if (temp->next != NULL)
            temp->next->prev = NULL;
    }
    // If node is in the middle or end
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Sample creation of list: 10 -> 20 -> 30
struct Node* createList() {
    struct Node* head = NULL;
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10; n1->prev = NULL; n1->next = n2;
    n2->data = 20; n2->prev = n1;   n2->next = n3;
    n3->data = 30; n3->prev = n2;   n3->next = NULL;

    head = n1;
    return head;
}

int main() {
    struct Node* head = createList();
    
    printf("Original ");
    printList(head);

    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    deleteNode(&head, key);

    printf("After deletion ");
    printList(head);

    return 0;
}
