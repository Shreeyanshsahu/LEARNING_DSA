#include <stdio.h>
#define SIZE 100

void writeArray(int arr[], int *n) {
    int i;
    printf("Enter size of array: ");
    scanf("%d", n);
    if (*n > SIZE) {
        printf("Size exceeds maximum allowed.\n");
        *n = 0;
        return;
    }
    printf("Enter %d elements:\n", *n);
    for (i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray(int arr[], int n) {
    int i, temp;
    for (i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

void insertElement(int arr[], int *n, int pos, int elem) {
    int i;
    if (*n >= SIZE) {
        printf("Array is full!\n");
        return;
    }
    for (i = *n; i >= pos; i--)
        arr[i] = arr[i-1];
    arr[pos-1] = elem;
    (*n)++;
    printf("Element inserted.\n");
}

void deleteElement(int arr[], int *n, int pos) {
    int i;
    for (i = pos-1; i < *n-1; i++)
        arr[i] = arr[i+1];
    (*n)--;
    printf("Element deleted.\n");
}

void findMaxMin(int arr[], int n, int *max, int *min) {
    int i;
    *max = *min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

int main() {
    int arr[SIZE], n = 0, choice, pos, elem, max, min;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Write Array\n");
        printf("2. Display Array\n");
        printf("3. Reverse Array\n");
        printf("4. Insert Element\n");
        printf("5. Delete Element\n");
        printf("6. Find Maximum and Minimum\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                writeArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                reverseArray(arr, n);
                printf("Array reversed.\n");
                break;
            case 4:
                printf("Enter position to insert (1 to %d): ", n+1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n+1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                insertElement(arr, &n, pos, elem);
                break;
            case 5:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                deleteElement(arr, &n, pos);
                break;
            case 6:
                if (n == 0) {
                    printf("Array is empty!\n");
                    break;
                }
                findMaxMin(arr, n, &max, &min);
                printf("Maximum: %d, Minimum: %d\n", max, min);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
