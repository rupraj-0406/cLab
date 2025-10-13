#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "heap.h"

#define scan(d,n) scanf("%"#d,&n)
#define ll long long

int minHeapComparator(void *arr, int i, int j) {
    int *numbers = (int *)arr;
    if (numbers[i] < numbers[j]) {
        return 1;
    } else if (numbers[i] > numbers[j]) {
        return -1;
    }
    return 0;
}

int maxHeapComparator(void *arr, int i, int j) {
    int *numbers = (int *)arr;
    if (numbers[i] > numbers[j]) {
        return 1;
    } else if (numbers[i] < numbers[j]) {
        return -1;
    }
    return 0;
}

HEAP H;
void solve() {
    int arr[] = {4, 2, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    initHeap(&H, sizeof(int), minHeapComparator);
    for (int i = 0; i < n; i++) {
        insert(&H, &arr[i]);
    }

    long long cost = 0;
    while (H.num_used > 1) {
        int first, second;
        deleteMax(&H, &first);
        deleteMax(&H, &second);
        int rope = first + second;
        cost += rope;
        insert(&H, &rope);
    }

    printf("\n%lld\n", cost);
}


int main(){
    //int t; scan(d,t); while(t--)
    solve();

    return 0;
}