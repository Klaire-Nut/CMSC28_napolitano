//Written by: Klaire Napolitano 1-BSCS
//Date: 04-10-24

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Structure definition for a node in the queue
struct Node {
    char name[50];
    float totalAmount;
    struct Node* next;
};

// Structure definition for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node with given name and totalAmount
struct Node* createNode(char name[], float totalAmount) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->totalAmount = totalAmount;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* init() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool empty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to return the front item of the queue
struct Node* front(struct Queue* q) {
    if (empty(q)) {
        printf("The QUEUE is EMPTY.\n");
        return NULL;
    }
    return q->front;
}

// Function to insert an item into the queue
void enqueue(char name[], float totalAmount, struct Queue* q) {
    struct Node* newNode = createNode(name, totalAmount);
    if (empty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove and return the front item of the queue
struct Node* dequeue(struct Queue* q) {
    if (empty(q)) {
        printf("The QUEUE is EMPTY.\n");
        return NULL;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

// Function to serve customer
void serveCustomer(struct Queue* q) {
    if (empty(q)) {
        printf("The QUEUE is EMPTY. No orders to serve.\n");
        return;
    }
    struct Node* servedCustomer = dequeue(q);
    printf("Now serving %s with total amount payable of %.4f \n", servedCustomer->name, servedCustomer->totalAmount);
    free(servedCustomer);
}

// Function to display next customer in the Queue
void displayNextCustomer(struct Queue* q) {
    if (empty(q)) {
        printf("The QUEUE is EMPTY. No order to serve.\n");
        return;
    }
    struct Node* nextCustomer = front(q);
    printf("Next order: For %s with total amount payable of %.4f \n", nextCustomer->name, nextCustomer->totalAmount);
}

// Function to serve all remaining customers in the Queue
void closingTime(struct Queue* q) {
    if (empty(q)) {
        printf("The QUEUE is EMPTY. No remaining customer/s to serve.\n");
        return;
    }
    printf("Closing time! Serving all remaining customer/s in the QUEUE:\n");
    while (!empty(q)) {
        serveCustomer(q);
    }
    printf("All customers have been served.\n");
}

// Function to check if a string contains only alphabetic characters
bool isAlphaString(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]))
            return false;
    }
    return true;
}

// Main function
int main() {
    // Initialize the queue
    struct Queue* checkoutQueue = init();
    int choice;
    char name[50]; // temporary buffer for customer's name
    float totalAmount;

    // Display the main menu
    do {
        printf("============================================================================================================\n");
        printf("| SM Department Store Counter 0:                                                                           |\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("[1] Fall in line\n");
        printf("[2] Serve customer\n");
        printf("[3] Next customer\n");
        printf("[4] Closing time\n");
        printf("[0] Exit\n");
        printf("============================================================================================================\n");
        printf("Enter choice: ");

        // Check if the input is an integer
        if (scanf("%d", &choice) != 1) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid option.\n");
            continue;
        }

        switch (choice) {
            case 1: // Fall in line
                printf("Enter customer's name (letters only): ");
                scanf("%s", name);
                if (!isAlphaString(name)) {
                    printf("Invalid input. Please enter letters only.\n");
                    break;
                }
                printf("Enter total amount of items: ");
                if (scanf("%f", &totalAmount) != 1 || totalAmount < 0) {
                    printf("Invalid input. Please enter a non-negative number.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    break;
                }
                enqueue(name, totalAmount, checkoutQueue);
                break;

            case 2: // Serve customer
                serveCustomer(checkoutQueue);
                break;

            case 3: // Next customer
                displayNextCustomer(checkoutQueue);
                break;

            case 4: // Closing time
                closingTime(checkoutQueue);
                break;

            case 0: // Exit
                printf("Exiting. Checkout system terminated.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
