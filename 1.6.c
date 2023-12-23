#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
  int data;
  struct Node* next;
};

// Declare a global pointer to the last node of the list
struct Node* last = NULL;

// Function to create a circular linked list with n nodes
void createList(int n) {
  int i, data;
  struct Node *newNode, *prevNode;
  if (n <= 0) {
    printf("Invalid number of nodes.\n");
    return;
  }
  // Create the first node
  newNode = (struct Node*)malloc(sizeof(struct Node));
  printf("Enter data for node 1: ");
  scanf("%d", &data);
  newNode->data = data;
  newNode->next = NULL;
  last = newNode; // Make the first node as the last node
  prevNode = newNode; // Store the first node as the previous node
  // Create the remaining nodes
  for (i = 2; i <= n; i++) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node %d: ", i);
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    prevNode->next = newNode; // Link the previous node with the new node
    prevNode = newNode; // Update the previous node
  }
  prevNode->next = last; // Link the last node with the first node
}

// Function to display the list
void displayList() {
  struct Node* temp;
  if (last == NULL) {
    printf("List is empty.\n");
    return;
  }
  temp = last->next; // Point to the first node
  printf("The list contains:\n");
  do {
    printf("%d ", temp->data); // Print the data of the current node
    temp = temp->next; // Move to the next node
  } while (temp != last->next); // Repeat until the first node is visited again
  printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (last == NULL) {
    // List is empty, make the new node as the only node
    last = newNode;
    last->next = last;
  } else {
    // List is not empty, insert the new node before the first node
    newNode->next = last->next;
    last->next = newNode;
  }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (last == NULL) {
    // List is empty, make the new node as the only node
    last = newNode;
    last->next = last;
  } else {
    // List is not empty, insert the new node after the last node
    newNode->next = last->next;
    last->next = newNode;
    last = newNode; // Update the last node pointer
  }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning() {
  struct Node* temp;
  if (last == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (last->next == last) {
    // List has only one node, delete it and make the list empty
    temp = last;
    last = NULL;
    free(temp);
  } else {
    // List has more than one node, delete the first node and update the last node pointer
    temp = last->next;
    last->next = temp->next;
    free(temp);
  }
}

// Function to delete a node from the end of the list
void deleteFromEnd() {
  struct Node* temp, *prev;
  if (last == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (last->next == last) {
    // List has only one node, delete it and make the list empty
    temp = last;
    last = NULL;
    free(temp);
  } else {
    // List has more than one node, delete the last node and update the last node pointer
    temp = last;
    prev = last->next; // Point to the first node
    while (prev->next != last) {
      // Find the second last node
      prev = prev->next;
    }
    prev->next = last->next; // Link the second last node with the first node
    last = prev; // Update the last node pointer
    free(temp);
  }
}

// Main function to test the above functions
int main() {
  int n, data, choice;
  printf("Enter the number of nodes to create: ");
  scanf("%d", &n);
  createList(n); // Create a list with n nodes
  while (1) {
    printf("\nMenu:\n");
    printf("1. Display the list\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at end\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        displayList();
        break;
      case 2:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        insertAtBeginning(data);
        break;
      case 3:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        insertAtEnd(data);
        break;
      case 4:
        deleteFromBeginning();
        break;
      case 5:
        deleteFromEnd();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}
