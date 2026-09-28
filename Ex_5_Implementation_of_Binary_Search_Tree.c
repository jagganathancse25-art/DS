PROGRAM:

#include <stdio.h>
#include <stdlib.h>

struct BST {
     int data;
    struct BST *lchild;
     struct BST *rchild;
};
typedef struct BST * NODE;

NODE create() {
     NODE temp;
     temp = (NODE) malloc(sizeof(struct BST));
     printf("\nEnter The value: ");
     scanf("%d", &temp->data);
     temp->lchild = NULL;
     temp->rchild = NULL;
     return temp;
}

void insert(NODE root, NODE newnode) {
     if (newnode->data < root->data) {
         if (root->lchild == NULL)
             root->lchild = newnode;
         else
             insert(root->lchild, newnode);
     } else if (newnode->data > root->data) {
         if (root->rchild == NULL)
             root->rchild = newnode;
         else
             insert(root->rchild, newnode);
     }
     // duplicates skipped
}

void inorder(NODE root) {
     if (root != NULL) {
         inorder(root->lchild);
         printf("%d ", root->data);
         inorder(root->rchild);
     }
}

void preorder(NODE root) {
     if (root != NULL) {
         printf("%d ", root->data);
         preorder(root->lchild);
         preorder(root->rchild);
     }
}

void postorder(NODE root) {
     if (root != NULL) {
         postorder(root->lchild);
         postorder(root->rchild);
         printf("%d ", root->data);
     }
}

void search(NODE root) {
     int key;
     printf("Enter key to search: ");
     scanf("%d", &key);
     while (root != NULL) {
         if (key == root->data) {
             printf("Element found\n");
             return;
         } else if (key < root->data)
             root = root->lchild;
         else
             root = root->rchild;
     }
     printf("Element not found\n");
}

int main() {
     NODE root = NULL, newnode;
     int choice;
     while (1) {
         printf("\n1. Insert 2. Inorder 3. Preorder 4. Postorder 5. Search 6. Exit\n");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 newnode = create();
                 if (root == NULL) root = newnode;
                 else insert(root, newnode);
                 break;
             case 2:
                 printf("Inorder: "); inorder(root); printf("\n"); break;
             case 3:
                 printf("Preorder: "); preorder(root); printf("\n"); break;
             case 4:
                 printf("Postorder: "); postorder(root); printf("\n"); break;
             case 5:
                 search(root); break;
             case 6:
                 exit(0);
             default:
                 printf("Invalid\n");
         }
     }
     return 0;
}
