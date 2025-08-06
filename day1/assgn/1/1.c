#include<stdio.h>


int check(int arr[]){
    int sum=0;
    for (int i = 0; i < 10; i++)
    {
        sum+=(arr[i]*(i+1));
        sum%=11;
    }
    
    return sum;
}
int main(){
    char str[10];
    scanf("%s",str);
    int arr[10],brr[10],k;
    for(int i=0;i<10;i++){
        k=(int)str[i]-48;
        arr[i]=k;
        brr[i]=k;
    }
    int ans=check(arr);
    printf("%d-",arr[0]);
    for(int i=1;i<4;i++){
        printf("%d",brr[i]);
    }
    printf("-");
    for(int i=4;i<9;i++){
        printf("%d",brr[i]);
    }
    // printf("-");
    printf("%d\n",ans);
    return 0;
}