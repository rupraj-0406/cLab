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
        k=(int)str[i];
        arr[i]=k;
        brr[i]=k;
    }
    int ans=check(ans);
    printf("%d",ans);
    return 0;
}