#include<stdio.h>
#include<string.h>

void rev(char *str, int n){
    int s=0;
    int e=n-1;
    char temp;
    while(s<e){
        temp = str[s];
        str[s] = str[e];
        str[e] = temp;

        // Move the pointers towards the middle
        s++;
        e--;
    }
}
int main(){
    char str[80];
    scanf("%s",str);
    int n=strlen(str);
    rev(str,n);
    printf("%s\n",str);
    return 0;
}