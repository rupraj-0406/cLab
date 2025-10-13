#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 100010

typedef int (*comparator)(int, int);

// Heap structure definition
typedef struct {
    int arr[MAX_SIZE];
    int size;
    int totalsize;
    comparator comp;
} heap;

// Comparator prototypes
int minHeap(int a, int b);
int maxHeap(int a, int b);

// Heap operations
void init(heap *H, int totalsize, comparator comp);
void insert(heap *H, int val);
void delete(heap *H);
int getTop(heap *H);
#endif