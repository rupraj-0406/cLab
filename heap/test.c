#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "common.h"


HEAP mxh;
HEAP mnh;

int maxCompare(void* arr, int i,int j){
    int* nums=(int*)arr;
    if(nums[i]>nums[j])return 1;
    if(nums[i]<nums[j])return -1;
    return 0;
}

int minCompare(void* arr, int i,int j){
    int* nums=(int*)arr;
    if(nums[i]<nums[j])return 1;
    if(nums[i]>nums[j])return -1;
    return 0;
}

void insrt(int* n){
    int num=*n;
    if(mxh.num_used==0 ||num< ((int*)mxh.array)[1])
    insert(&mxh,&num);
    else
    insert(&mnh,&num);

    if(mxh.num_used>mnh.num_used+1){
        int temp;
        deleteMax(&mxh,&temp);
        insert(&mnh,&temp);
    }
    if(mxh.num_used<mnh.num_used){
        int tmp;
        deleteMax(&mnh,&tmp);
        insert(&mxh,&tmp);
    }
    return;
}
float getMedian(){

    if(mxh.num_used>mnh.num_used){
        return (float)((int*)mxh.array)[1];
    }else if(mxh.num_used<mnh.num_used){
        return (float)((int*)mnh.array)[1];
    }else 
    return ((float)((int*)mxh.array)[1]+(float)((int*)mnh.array)[1])/2.0;
    // return;
}

int main(){
    initHeap(&mxh,sizeof(int),maxCompare);
    initHeap(&mnh,sizeof(int),minCompare);

    char str[100];
    while(scanf("%s",str)!=EOF){
        if(strcmp(str,"insert")==0){
            int k;
            scanf("%d",&k);
            insrt(&k);
        }else if(strcmp(str,"getMedian")==0){
            printf("%f\n",getMedian());
        }
    }
    return 0;
}