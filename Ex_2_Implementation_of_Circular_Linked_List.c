PROGRAM:

#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node
typedef struct Node {
    int data;
    struct Node *next;
}Node;
// Define the structure for a Circular Linked List
typedef struct {
    Node *head;
} CircularLinkedList;
// Initialize the Circular Linked List
void initCircularLinkedList(CircularLinkedList *list) {
    list->head = NULL;
}
 // Function to add an element to the Circular Linked List
void addCircular(CircularLinkedList *list, int element) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
       fprintf(stderr, "Memory allocation failed\n");
       exit(EXIT_FAILURE);
    }
    new_node->data = element;
    new_node->next = NULL;
    if (list->head == NULL) {
       list->head = new_node;
       new_node->next = list->head;
    }
    else {
       Node *current = list->head;
       while (current->next != list->head) {
           current = current->next;
       }
       current->next = new_node;
       new_node->next = list->head;
    }
 }
// Function to remove an element from the Circular Linked List
void removeCircular(CircularLinkedList *list, int element) {
    if (list->head == NULL) {
       printf("List is empty\n");
       return;
    }
    Node *current = list->head;
    Node *prev = NULL;
    do {
       if (current->data == element) {
           if (current == list->head && current->next == list->head) {
              list->head = NULL;
           }
           else if (current == list->head) {
              // handle head removal
              Node *last = list->head;
              while (last->next != list->head) last = last->next;
              list->head = current->next;
              last->next = list->head;
              free(current);
              return;
           }
           else {
              prev->next = current->next;
              free(current);
              return;
           }
       }
       prev = current;
       current = current->next;
    } while (current != list->head);
    printf("Element not found\n");
}
void displayCircular(CircularLinkedList *list) {
    if (list->head == NULL) {
       printf("List is empty\n");
       return;
    }
    Node *current = list->head;
    do {
       printf("%d -> ", current->data);
       current = current->next;
    } while (current != list->head);
    printf("(back to head)\n");
}
int main() {
    CircularLinkedList list;
    initCircularLinkedList(&list);
    addCircular(&list, 10);
    addCircular(&list, 20);
    addCircular(&list, 30);
    displayCircular(&list);
    removeCircular(&list, 20);
    displayCircular(&list);
    return 0;
}
