PROGRAM:

#include <stdio.h>
#include <stdlib.h>

struct heap {
     int c; // capacity
     int s; // size
     int *element;
};

typedef struct heap *pqueue;

pqueue initialize(int max) {
     pqueue heap1;
     if (max <= 3) {
         printf("\n Priority queue is too small\n");
         exit(EXIT_FAILURE);
     }
     heap1 = (pqueue)malloc(sizeof(struct heap));
     if (heap1 == NULL) {
         printf("\n Out of space\n");
         exit(EXIT_FAILURE);
     }
     heap1->element = (int *)malloc((max + 1) * sizeof(int));
     if (heap1->element == NULL) {
         printf("\n Out of space\n");
         exit(EXIT_FAILURE);
     }
     heap1->c = max;
     heap1->s = 0;
     heap1->element[0] = 0;
     return heap1;
}

void insert(int x, pqueue H) {
     int i;
     if (H->s == H->c) {
         printf("Priority queue is full\n");
         return;
     }
     for (i = ++H->s; H->element[i/2] > x; i /= 2)
         H->element[i] = H->element[i/2];
     H->element[i] = x;
}

int deleteMin(pqueue H) {
     int i, child;
     int min, last;
     if (H->s == 0) {
         printf("Priority queue is empty\n");
         return -1;
     }
     min = H->element[1];
     last = H->element[H->s--];
     for (i = 1; i * 2 <= H->s; i = child) {
         child = i * 2;
         if (child != H->s && H->element[child + 1] < H->element[child])
             child++;
         if (last > H->element[child])
             H->element[i] = H->element[child];
         else
             break;
     }
     H->element[i] = last;
     return min;
}

void display(pqueue H) {
     printf("Priority Queue elements: ");
     for (int i = 1; i <= H->s; i++)
         printf("%d ", H->element[i]);
     printf("\n");
}

int main() {
     pqueue H = initialize(10);
     int choice, x;
     while (1) {
         printf("\n1. Insert 2. DeleteMin 3. Display 4. Exit\n");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 printf("Enter element: ");
                 scanf("%d", &x);
                 insert(x, H);
                 break;
             case 2:
                 x = deleteMin(H);
                 if (x != -1) printf("Deleted min: %d\n", x);
                 break;
             case 3:
                 display(H);
                 break;
             case 4:
                 return 0;
             default:
                 printf("Invalid\n");
         }
     }
     return 0;
}
