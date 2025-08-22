#include <stdio.h>
#include<string.h>
#include <ctype.h>
void freq(char str[],int n){
    int cnt[26] = {0};
    char c;
     for (int i = 0; i<n; i++) {
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))str[i] = tolower(str[i]);
        else continue;
    }
    for(int i=0;i<n;i++){
        if (str[i] >= 'a' && str[i] <= 'z') {
            cnt[str[i] - 'a']++;
        }
    }

    printf("|Letter | Count |\n");
    printf("|---------------|\n");
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            printf("|   %c   |   %d   |\n", 'a' + i, cnt[i]);
        }
    }


	
}
int main() {
    int cnt[26] = {0}; 
    char c;

    char str[1001];
    // scanf("%s",str);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;//remove newlines add
    				//
    int n=strlen(str);
    freq(str,n);
//
    /* for (int i = 0; i<n; i++) {
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))str[i] = tolower(str[i]);
        else continue;
    }
    for(int i=0;i<n;i++){
        if (str[i] >= 'a' && str[i] <= 'z') {
            cnt[str[i] - 'a']++;
        }
    }

    printf("|Letter | Count |\n");
    printf("|---------------|\n");
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            printf("|   %c   |   %d   |\n", 'a' + i, cnt[i]);
        }
    }*/

    return 0;
}
