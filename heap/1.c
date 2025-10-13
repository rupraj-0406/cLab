/*

1 # number of test cases
4 # test case 1: number of sorted lists
3 10 20 30 # list 1: number of elements, followed by elements in sorted order
2 1 2 # list 2: as abov
5 5 15 25 30 35 # list 3
4 3 9 27 81 # list 4

*/ 

#include "common.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LISTS 100
#define MAX_ELEMENTS 1000

// A struct to hold a single element and its list-specific information
typedef struct {
    int value; // Assuming integer type for simplicity based on the example input
    int list_index;
    int element_index;
} ElementNode;

// Min-heap comparator function
int minHeapComparator(void *a, int i, int j) {
    ElementNode *nodes = (ElementNode *)a;
    // Invert the comparison to make a min-heap
    if (nodes[i].value < nodes[j].value) {
        return 1;
    } else if (nodes[i].value > nodes[j].value) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    while (num_test_cases--) {
        int num_lists;
        scanf("%d", &num_lists);

        int lists[MAX_LISTS][MAX_ELEMENTS];
        int list_sizes[MAX_LISTS];

        // Read all lists
        for (int i = 0; i < num_lists; i++) {
            scanf("%d", &list_sizes[i]);
            for (int j = 0; j < list_sizes[i]; j++) {
                scanf("%d", &lists[i][j]);
            }
        }

        // Initialize min-heap
        HEAP h;
        initHeap(&h, sizeof(ElementNode), minHeapComparator);

        // Insert the first element of each list into the min-heap
        for (int i = 0; i < num_lists; i++) {
            if (list_sizes[i] > 0) {
                ElementNode node = {lists[i][0], i, 0};
                insert(&h, &node);
            }
        }

        // Merge the lists
        printf("Merged List: ");
        //
        HEAP newh;
        initHeap(&newh,sizeof(ElementNode),minHeapComparator);
        //
        while (h.num_used > 0) {
            ElementNode min_node;
            deleteMax(&h, &min_node); // deleteMax acts as deleteMin with our comparator
            insert(&newh,&min_node);
            printf("%d ", min_node.value);

            // Get the next element from the same list
            int next_element_index = min_node.element_index + 1;
            if (next_element_index < list_sizes[min_node.list_index]) {
                ElementNode new_node = {lists[min_node.list_index][next_element_index],
                                        min_node.list_index,
                                        next_element_index};
                insert(&h, &new_node);
            }
        }
        printf("\n");
        int z=newh.num_used;
        int *arr=(int *)malloc(z*sizeof(int));
        int i=0;
        while (newh.num_used>0)
        {
            /* code */
            ElementNode newN;
            deleteMax(&newh,&newN);
            arr[i++]=newN.value;            

        }
        printf("the array in the form of array...\n");
        z=sizeof(arr)/sizeof(arr[0]);
        printf("z=%d\n",z);
        for(int m=0;m<z;m++)printf("%d ",arr[i]);
        free(arr);
        printf("\n");
        
    }
    

    return 0;
}