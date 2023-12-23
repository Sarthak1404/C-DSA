#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

// Declare a global pointer to the head and tail of the list
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to create a doubly linked list with n nodes
void createList(int n) {
  int i, data;
  struct Node *newNode, *temp;
  if (n <= 0) {
    printf("Invalid number of nodes.\n");
    return;
  }
  // Create the first node
  newNode = (struct Node*)malloc(sizeof(struct Node));
  printf("Enter data for node 1: ");
  scanf("%d", &data);
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  head = newNode; // Make the first node as the head node
  tail = newNode; // Make the first node as the tail node
  temp = newNode; // Store the first node as the temporary node
  // Create the remaining nodes
  for (i = 2; i <= n; i++) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node %d: ", i);
    scanf("%d", &data);
    newNode->data = data;
    newNode->prev = temp; // Link the new node with the previous node
    newNode->next = NULL;
    temp->next = newNode; // Link the previous node with the new node
    temp = newNode; // Update the temporary node
    tail = newNode; // Update the tail node
  }
}

// Function to display the list from head to tail
void displayListFromHead() {
  struct Node* temp;
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  temp = head; // Point to the head node
  printf("The list contains:\n");
  while (temp != NULL) {
    printf("%d ", temp->data); // Print the data of the current node
    temp = temp->next; // Move to the next node
  }
  printf("\n");
}

// Function to display the list from tail to head
void displayListFromTail() {
  struct Node* temp;
  if (tail == NULL) {
    printf("List is empty.\n");
    return;
  }
  temp = tail; // Point to the tail node
  printf("The list contains:\n");
  while (temp != NULL) {
    printf("%d ", temp->data); // Print the data of the current node
    temp = temp->prev; // Move to the previous node
  }
  printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  if (head == NULL) {
    // List is empty, make the new node as the only node
    head = newNode;
    tail = newNode;
  } else {
    // List is not empty, insert the new node before the head node
    newNode->next = head;
    head->prev = newNode;
    head = newNode; // Update the head node
  }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  if (tail == NULL) {
    // List is empty, make the new node as the only node
    head = newNode;
    tail = newNode;
  } else {
    // List is not empty, insert the new node after the tail node
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode; // Update the tail node
  }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning() {
  struct Node* temp;
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (head->next == NULL) {
    // List has only one node, delete it and make the list empty
    temp = head;
    head = NULL;
    tail = NULL;
    free(temp);
  } else {
    // List has more than one node, delete the head node and update the head pointer
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
  }
}

// Function to delete a node from the end of the list
void deleteFromEnd() {
  struct Node* temp;
  if (tail == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (tail->prev == NULL) {
    // List has only one node, delete it and make the list empty
    temp = tail;
    head = NULL;
    tail = NULL;
    free(temp);
  } else {
    // List has more than one node, delete the tail node and update the tail pointer
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
  }
}

// Main function to test the above functions
void main() {
  int n, data, choice;
  printf("Enter the number of nodes to create: ");
  scanf("%d", &n);
  createList(n); // Create a list with n nodes
  while (1) {
    printf("\nMenu:\n");
    printf("1. Display the list from head to tail\n");
    printf("2. Display the list from tail to head\n");
    printf("3. Insert at beginning\n");
    printf("4. Insert at end\n");
    printf("5. Delete from beginning\n");
    printf("6. Delete from end\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        displayListFromHead();
        break;
      case 2:
        displayListFromTail();
        break;
      case 3:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        insertAtBeginning(data);
        break;
      case 4:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        insertAtEnd(data);
        break;
      case 5:
        deleteFromBeginning();
        break;
      case 6:
        deleteFromEnd();
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
}
