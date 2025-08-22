#include <stdio.h>

int remove_duplicates(int* arr, int size) {
    if (size == 0) return 0;
    
    int j = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main() {
    int n;
    // printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    // printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int new_size = remove_duplicates(arr, n);
    
    printf("Number of distinct elements: %d\n", new_size);
    
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}