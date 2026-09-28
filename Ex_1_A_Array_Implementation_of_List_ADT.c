PROGRAM:

#include<stdio.h>
#define MAX_SIZE 100
void createArray(int arr[], int *size);
void insertElement(int arr[], int *size, int element, int position);
int searchElement(int arr[], int size, int element);
void deleteElement(int arr[], int *size, int position);
void displayArray(int arr[], int size);
int main() {
 
int arr[MAX_SIZE];
 
int size = 0;
 
int choice, element, position, result;
 
while(1) {
 
 
printf(“\nArray Operation Menu:\n”);
 
 
printf(“1. Create Array\n”);
 
 
printf(“2. Insert Element\n”);
 
 
printf(“3. Search Element\n”);
 
 
printf(“4. Delete Element\n”);
 
 
printf(“5. Display Array\n”);
 
 
printf(“6. Exit\n”);
 
 
printf(“Enter your choice: “);
 
 
scanf(“%d”, &choice);
 
 
switch(choice) {
 
 
 
case 1:
 
 
 
 
createArray(arr, &size);
 
 
 
 
break;
 
 
 
case 2:
 
 
 
 
printf(“Enter element to insert: ”);
 
 
 
 
scanf(“%d”, &element);
 
 
 
 
printf(“Enter position to insert (0 to %d): ”, size);
 
 
 
 
scanf(“%d”, &position);
 
 
 
 
insertElement(arr, &size, element, position);
 
 
 
 
break;
 
 
 
case 3:
 
 
 
 
printf(“Enter element to search: “);
 
 
 
 
scanf(“%d”, &element);
 
 
 
 
result = searchElement(arr, size, element);
 
 
 
 
if(result != -1)
 
 
 
 
 
printf(“Element fount at position: %d\n”, result);
 
 
 
 
else
 
 
 
 
 
printf(“Element not found in the array\n”);
 
 
 
 
break;
 
 
 
case 4:
 
 
 
 
printf(“Enter position to delete (0 to %d): ”, size-1);
 
 
 
 
scanf(“%d”, &position);
 
 
 
 
deleteElement(arr, &size, position);
 
 
 
 
break;
 
 
 
case 5:
 
 
 
 
displayArray(arr, size);
 
 
 
 
break;
