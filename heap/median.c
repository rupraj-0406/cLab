#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "common.h"

// Define the two global heaps
HEAP max_heap; // For the smaller half of numbers
HEAP min_heap; // For the larger half of numbers

// Comparator for the max-heap (standard behavior)
int maxHeapComparator(void *arr, int i, int j) {
    int *numbers = (int *)arr;
    if (numbers[i] > numbers[j]) {
        return 1;
    } else if (numbers[i] < numbers[j]) {
        return -1;
    }
    return 0;
}

// Comparator for the min-heap (inverts the logic)
int minHeapComparator(void *arr, int i, int j) {
    int *numbers = (int *)arr;
    if (numbers[i] < numbers[j]) {
        return 1;
    } else if (numbers[i] > numbers[j]) {
        return -1;
    }
    return 0;
}

// Inserts a number into the data stream and maintains heap balance
void insrt(int num) {
    // Insert into the correct heap
    if (max_heap.num_used == 0 || num < ((int *)max_heap.array)[1]) {
        insert(&max_heap, &num);
    } else {
        insert(&min_heap, &num);
    }

    // Rebalance the heaps
    if (max_heap.num_used > min_heap.num_used + 1) {
        int temp;
        deleteMax(&max_heap, &temp);
        insert(&min_heap, &temp);
    } else if (min_heap.num_used > max_heap.num_used) {
        int temp;
        deleteMax(&min_heap, &temp); // deleteMax on a min-heap gets the min value
        insert(&max_heap, &temp);
    }
}

// Gets the current median from the data stream
float getMedian() {
    if (max_heap.num_used > min_heap.num_used) {
        return (float)((int *)max_heap.array)[1];
    } else if (min_heap.num_used > max_heap.num_used) {
        return (float)((int *)min_heap.array)[1];
    } else {
        return (float)(((int *)max_heap.array)[1] + ((int *)min_heap.array)[1]) / 2.0;
    }
}

int main() {
    char command[10];
    int num;

    // Initialize both heaps
    initHeap(&max_heap, sizeof(int), maxHeapComparator);
    initHeap(&min_heap, sizeof(int), minHeapComparator);

    printf("Enter commands (e.g., 'insert 10', 'getMedian', 'exit'):\n");
    while (1) {
        printf("> ");
        if (scanf("%s", command) == EOF) {
            break;
        }

        if (strcmp(command, "insert") == 0) {
            if (scanf("%d", &num) == 1) {
                insrt(num);
                printf("Inserted %d\n", num);
            }
        } else if (strcmp(command, "getMedian") == 0) {
            if (max_heap.num_used == 0 && min_heap.num_used == 0) {
                printf("No numbers in the stream.\n");
            } else {
                printf("Median: %.2f\n", getMedian());
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Clean up memory
    free(max_heap.array);
    free(min_heap.array);

    return 0;
}