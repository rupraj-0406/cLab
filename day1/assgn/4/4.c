#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n], check[n],flag=0;
    for (int i = 0; i < n; i++) check[i] = 0;
    for(int i=0;i<n;i++)scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        
        if (a[i] < 0 || a[i] >= n || check[a[i]] == 1) {//checking validity
            flag=1;
            break;
        }
        check[a[i]] = 1;
    }

    if(flag==0){//valid
    for (int i = 0; i < n; i++) {
        b[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");}
    else printf("Invalid");
    return 0;
}
