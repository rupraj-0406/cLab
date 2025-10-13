#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "heap.h"

#define scan(d,n) scanf("%"#d,&n)
#define mod 1000000007
#define ll long long

HEAP H;

int maxHeapComparator(void *arr, int i, int j) {
    int *numbers = (int *)arr;
    if (numbers[i] > numbers[j]) {
        return 1;
    } else if (numbers[i] < numbers[j]) {
        return -1;
    }
    return 0;
}

void maxChoc(int* a,int b[],int n){
    initHeap(&H,sizeof(int),maxHeapComparator);

    for(int i=0;i<n;i++){
        insert(&H,&b[i]);
    }

    ll ans=0;
    while(((*a)>0) && (H.num_used!=0)){
        printf("chocolate: %lld",ans);
        ans+=((int *)H.array)[1];
        printf(" curr:%d\n",((int *)H.array)[1]);
        int tmp=(((int *)H.array)[1])/2;
        printf(" temp:%d\n",tmp);
        if(tmp>=0)
            insert(&H,&tmp);

        deleteMax(&H,&tmp);
        --(*a);
    }
    printf("\nanswer: %lld\n",ans%mod);
}

void solve(){
    int a=5;
    int b[]={2,6,8,4,10};
    int n=sizeof(b)/sizeof(b[0]);

    maxChoc(&a,b,n);
}

int main(){
    //int t; scan(d,t); while(t--)
    solve();

    return 0;
}