#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a node structure for a polynomial term
struct Node {
  float coeff; // coefficient of the term
  int exp; // exponent of the term
  struct Node* next; // pointer to the next term
};

// Function to create a new node and return its pointer
struct Node* createNode(float coeff, int exp) {
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
void insertNode(struct Node** head, float coeff, int exp) {
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
    printf("%.2f", fabs(temp->coeff));
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

// Function to evaluate a polynomial linked list for a given value of x
float evaluateList(struct Node* head, float x) {
  float result = 0; // variable to store the result
  struct Node* temp = head; // temporary pointer to traverse the list
  while (temp != NULL) {
    // loop until the end of the list
    // add the value of the current term to the result
    result += temp->coeff * pow(x, temp->exp);
    temp = temp->next; // move to the next term
  }
  return result; // return the result
}

// Main function to test the above functions
void main() {
  struct Node* poly = NULL; // pointer to the head of the polynomial linked list
  int n; // variable to store the number of terms
  float coeff, x; // variables to store the coefficient and the value of x
  int exp; // variable to store the exponent
  printf("Enter the number of terms in the polynomial: ");
  scanf("%d", &n); // read the number of terms
  for (int i = 0; i < n; i++) {
    // loop for each term
    printf("Enter the coefficient and exponent of term %d: ", i + 1);
    scanf("%f%d", &coeff, &exp); // read the coefficient and exponent
    insertNode(&poly, coeff, exp); // insert the term to the list
  }
  printf("The polynomial is: ");
  displayList(poly); // display the list
  printf("Enter the value of x: ");
  scanf("%f", &x); // read the value of x
  printf("The value of the polynomial for x = %.2f is: %.2f\n", x, evaluateList(poly, x)); // evaluate and print the value of the polynomial
 
}
