PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
     int data;
     struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void push(struct Node** top, int data);
int pop(struct Node** top);
void displayStack(struct Node* top);

int main() {
     struct Node* top = NULL;
     int choice, element;
     while (1) {
         printf("\nStack Operations Menu:\n");
         printf("1. Push\n");
         printf("2. Pop\n");
         printf("3. Display\n");
         printf("4. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 printf("Enter element to push: ");
                 scanf("%d", &element);
                 push(&top, element);
                 break;
             case 2:
                 element = pop(&top);
                 if (element != -1)
                     printf("Popped: %d\n", element);
                 break;
             case 3:
                 displayStack(top);
                 break;
             case 4:
                 exit(0);
             default:
                 printf("Invalid choice\n");
         }
     }
     return 0;
}

struct Node* createNode(int data) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
}

void push(struct Node** top, int data) {
     struct Node* newNode = createNode(data);
     newNode->next = *top;
     *top = newNode;
     printf("Pushed %d\n", data);
}

int pop(struct Node** top) {
     if (*top == NULL) {
         printf("Stack underflow\n");
         return -1;
     }
     struct Node* temp = *top;
     int data = temp->data;
     *top = (*top)->next;
     free(temp);
     return data;
}

void displayStack(struct Node* top) {
     if (top == NULL) {
         printf("Stack is empty\n");
         return;
     }
     printf("Stack: ");
     while (top != NULL) {
         printf("%d ", top->data);
         top = top->next;
     }
     printf("\n");
}
