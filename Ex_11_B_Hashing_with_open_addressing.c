PROGRAM:

#include <stdio.h>
#include <limits.h>

void insert(int ary[], int hFn, int size) {
     int element, pos, n = 0;
     printf("Enter key element to insert\n");
    scanf("%d", &element);
     pos = element % hFn;
     while (ary[pos] != INT_MIN) {
         // INT_MIN and INT_MAX indicate that cell is empty or deleted
         if (ary[pos] == INT_MAX)
             break;
         pos = (pos + 1) % hFn;
         n++;
         if (n == size) {
             printf("Hash table is full. No place to insert this element.\n");
             return;
         }
     }
     ary[pos] = element;
 // Inserting element
 }

void delete(int ary[], int hFn, int size) {
     int element, pos, n = 0;
     printf("Enter element to delete\n");
     scanf("%d", &element);
     pos = element % hFn;
     while (n++ != size) {
         if (ary[pos] == INT_MIN) {
             printf("Element not found\n");
             return;
         }
         if (ary[pos] == element) {
             ary[pos] = INT_MAX; // Mark as deleted
             printf("Element deleted\n");
             return;
         }
         pos = (pos + 1) % hFn;
     }
     printf("Element not found\n");
 }

void search(int ary[], int hFn, int size) {
     int element, pos, n = 0;
     printf("Enter element to search\n");
     scanf("%d", &element);
     pos = element % hFn;
     while (n++ != size) {
         if (ary[pos] == INT_MIN) {
             printf("Element not found\n");
             return;
         }
         if (ary[pos] == element) {
             printf("Element found at position %d\n", pos);
             return;
         }
         pos = (pos + 1) % hFn;
     }
     printf("Element not found\n");
 }

void display(int ary[], int size) {
     printf("Hash table contents:\n");
     for (int i = 0; i < size; i++) {
         if (ary[i] == INT_MIN)
             printf("[%d] : Empty\n", i);
         else if (ary[i] == INT_MAX)
             printf("[%d] : Deleted\n", i);
         else
             printf("[%d] : %d\n", i, ary[i]);
     }
 }

int main() {
     int size, hFn, choice;
     printf("Enter size of hash table: ");
     scanf("%d", &size);
     printf("Enter hash function (mod value): ");
     scanf("%d", &hFn);
     int ary[size];
     for (int i = 0; i < size; i++) ary[i] = INT_MIN;
     while (1) {
         printf("\n1. Insert 2. Delete 3. Search 4. Display 5. Exit\n");
         scanf("%d", &choice);
         switch (choice) {
             case 1: insert(ary, hFn, size); break;
             case 2: delete(ary, hFn, size); break;
             case 3: search(ary, hFn, size); break;
             case 4: display(ary, size); break;
             case 5: return 0;
             default: printf("Invalid choice\n");
         }
     }
     return 0;
}
