#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a polynomial term
struct Node {
  int coeff; // coefficient of the term
  int exp; // exponent of the term
  struct Node* next; // pointer to the next term
};

// Function to create a new node and return its pointer
struct Node* createNode(int coeff, int exp) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for the node
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newNode->coeff = coeff; // assign the coefficient
  newNode->exp = exp; // assign the exponent
  newNode->next = NULL; // initialize the next pointer to NULL
  return newNode; // return the node pointer
}

// Function to insert a node at the end of a polynomial linked list
void insertNode(struct Node** head, int coeff, int exp) {
  struct Node* newNode = createNode(coeff, exp); // create a new node
  if (*head == NULL) {
    // if the list is empty, make the new node as the head
    *head = newNode;
  } else {
    // if the list is not empty, find the last node and insert the new node after it
    struct Node* temp = *head; // temporary pointer to traverse the list
    while (temp->next != NULL) {
      // loop until the last node is found
      temp = temp->next;
    }
    temp->next = newNode; // link the last node with the new node
  }
}

// Function to display a polynomial linked list
void displayList(struct Node* head) {
  struct Node* temp = head; // temporary pointer to traverse the list
  int flag = 0; // flag to indicate the first term
  while (temp != NULL) {
    // loop until the end of the list
    if (flag != 0) {
      // if not the first term, print the sign of the coefficient
      if (temp->coeff > 0) {
        printf(" + ");
      } else {
        printf(" - ");
      }
    }
    // print the absolute value of the coefficient
    printf("%d", abs(temp->coeff));
    if (temp->exp != 0) {
      // if the exponent is not zero, print x and the exponent
      printf("x");
      if (temp->exp != 1) {
        // if the exponent is not one, print ^ and the exponent
        printf("^%d", temp->exp);
      }
    }
    temp = temp->next; // move to the next term
    flag = 1; // set the flag to indicate not the first term
  }
  printf("\n"); // print a new line at the end
}

// Function to add two polynomials using linked list
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
  struct Node* result = NULL; // pointer to the head of the result list
  struct Node* tail = NULL; // pointer to the last node of the result list
  struct Node* node = NULL; // pointer to the new node to be inserted
  // Traverse both lists until one of them is null
  while (poly1 != NULL && poly2 != NULL) {
    // Compare the exponents of the current nodes
    if (poly1->exp == poly2->exp) {
      // If the exponents are equal, add the coefficients and create a new node with the same exponent
      node = createNode(poly1->coeff + poly2->coeff, poly1->exp);
      // Move both pointers to the next nodes
      poly1 = poly1->next;
      poly2 = poly2->next;
    } else if (poly1->exp > poly2->exp) {
      // If the exponent of poly1 is greater, create a new node with the coefficient and exponent of poly1
      node = createNode(poly1->coeff, poly1->exp);
      // Move the pointer of poly1 to the next node
      poly1 = poly1->next;
    } else {
      // If the exponent of poly2 is greater, create a new node with the coefficient and exponent of poly2
      node = createNode(poly2->coeff, poly2->exp);
      // Move the pointer of poly2 to the next node
      poly2 = poly2->next;
    }
    // Insert the new node at the end of the result list
    if (result == NULL) {
      // If the result list is empty, make the new node as the head and the tail
      result = node;
      tail = node;
    } else {
      // If the result list is not empty, link the tail node with the new node and update the tail pointer
      tail->next = node;
      tail = node;
    }
  }
  // Append the remaining nodes of either list to the result list
  if (poly1 != NULL) {
    // If poly1 is not null, link the tail node with poly1
    tail->next = poly1;
  }
  if (poly2 != NULL) {
    // If poly2 is not null, link the tail node with poly2
    tail->next = poly2;
  }
  // Return the result list
  return result;
}

// Main function to test the above functions
void main() {
  struct Node* poly1 = NULL; // pointer to the head of the first polynomial list
  struct Node* poly2 = NULL; // pointer to the head of the second polynomial list
  struct Node* poly3 = NULL; // pointer to the head of the result polynomial list
  int n, coeff, exp; // variables to store the number of terms, coefficient and exponent
  // Input the first polynomial
  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n); // read the number of terms
  for (int i = 0; i < n; i++) {
    // loop for each term
    printf("Enter the coefficient and exponent of term %d: ", i + 1);
    scanf("%d%d", &coeff, &exp); // read the coefficient and exponent
    insertNode(&poly1, coeff, exp); // insert the term to the list
  }
  // Input the second polynomial
  printf("Enter the number of terms in the second polynomial: ");
  scanf("%d", &n); // read the number of terms
  for (int i = 0; i < n; i++) {
    // loop for each term
    printf("Enter the coefficient and exponent of term %d: ", i + 1);
    scanf("%d%d", &coeff, &exp); // read the coefficient and exponent
    insertNode(&poly2, coeff, exp); // insert the term to the list
  }
  // Display the polynomials
  printf("The first polynomial is: ");
  displayList(poly1); // display the first list
  printf("The second polynomial is: ");
  displayList(poly2); // display the second list
  // Add the polynomials
  poly3 = addPolynomials(poly1, poly2); // add the lists and store the result in poly3
  // Display the result
  printf("The sum of the polynomials is: ");
  displayList(poly3); // display the result list
}
