#include<stdio.h>
#include<limits.h>
int main(){
	int arr[]={-4,2,-3,1,4,-1,-2,5,-3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int st,ars=-1,are=-1;
	int sum=0, ans=INT_MIN;

	for(int i=0;i<n;i++){
		if(sum==0)st=i;
		sum+=arr[i];
		if(sum>ans){
			ans=sum;
			ars=st;
			are=i;
		}
		if(sum<0)sum=0;
	}
	printf("arr= ");
	for(int i=0;i<n;i++)printf("%d ",arr[i]);
	printf("\n");
	printf("max sum subarray is: %d\n",ans);
	printf("Starts at: %d\nEnds at:%d\n",ars,are);
	return 0;
}
