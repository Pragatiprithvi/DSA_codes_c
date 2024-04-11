//Deletion in  Doubly Linked list 

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if ((*head)->next == *head) {
        *head = NULL;
    } else {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
    }
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = (*head)->prev;
    if ((*head)->next == *head) {
        *head = NULL;
    } else {
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
    }
    free(temp);
}

// Function to delete a node from the middle of the list
void deleteFromMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position && current->next != *head; i++) {
        current = current->next;
    }
    if (current->next == *head) {
        printf("Position out of range\n");
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Inserting nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);

    // Displaying the list
    printf("Doubly Circular Linked List: ");
    displayList(head);

    // Deleting nodes
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromMiddle(&head, 2);

    // Displaying the list after deletion
    printf("Doubly Circular Linked List after deletion: ");
    displayList(head);

    return 0;
}