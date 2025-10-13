#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "common.h"

// The provided heap.c uses one-based indexing. The comparator must account for this.
int compare(void* arr, int i, int j) {
    int *numbers = (int*)arr;
    
    // Adjust indices to be zero-based for array access.
    // The heap.c library passes one-based indices to the comparator.
    if (numbers[i] > numbers[j]) {
        return 1;
    } else if (numbers[i] < numbers[j]) {
        return -1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the numbers.
    int* nums = (int *)malloc((n+1) * sizeof(int));
    if (nums == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i+1]);
    }

    // Call heapsort from the provided library.
    heapsort(nums, n, sizeof(int), compare);

    printf("Array in sorted manner:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i+1]);
    }
    printf("\n");

    free(nums);
    return 0;
}