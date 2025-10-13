#include "heap.h"
#include <stdio.h>

// Comparator function definitions
int minHeap(int a, int b) {
    return a < b;
}

int maxHeap(int a, int b) {
    return a > b;
}

// Initialize the heap
void init(heap *H, int totalsize, comparator comp) {
    H->size = 0;
    H->totalsize = totalsize;
    H->comp = comp;
}

// Heapify down from index i to maintain heap property
void heapifyDown(heap *H, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int target = i;

    if (left < H->size && H->comp(H->arr[left], H->arr[target]))
        target = left;
    if (right < H->size && H->comp(H->arr[right], H->arr[target]))
        target = right;

    if (target != i) {
        int temp = H->arr[i];
        H->arr[i] = H->arr[target];
        H->arr[target] = temp;
        heapifyDown(H, target);
    }
}

// Heapify up from index i to maintain heap property
void heapifyUp(heap *H, int i) {
    if (i && H->comp(H->arr[i], H->arr[(i - 1) / 2])) {
        int temp = H->arr[i];
        H->arr[i] = H->arr[(i - 1) / 2];
        H->arr[(i - 1) / 2] = temp;
        heapifyUp(H, (i - 1) / 2);
    }
}

// Insert a new element into the heap
void insert(heap *H, int val) {
    if (H->size == H->totalsize) {
        printf("Heap overflow\n");
        return;
    }
    H->arr[H->size++] = val;
    heapifyUp(H, H->size - 1);
}

// Remove top element from heap
void delete(heap *H) {
    if (H->size <= 0) {
        printf("Heap underflow\n");
        return;
    }
    H->arr[0] = H->arr[H->size - 1];
    H->size--;
    heapifyDown(H, 0);
}

// Get the top element of the heap
int getTop(heap *H) {
    if (H->size <= 0) {
        printf("Heap is empty\n");
        return -1;  // Or some error value
    }
    return H->arr[0];
}
