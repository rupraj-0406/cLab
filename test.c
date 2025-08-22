#include<stdio.h>
int main(){
	char str0[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    char str1[8] = { 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q' };
    char str2[8] = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's' };
    str1[0] = 'a'; str1[1] = 'b'; str1[2] = 'c'; str1[3] = '\0';
    // printf("%c\n",str1[6]);
    printf("%s\n%s\n%s\n", str0, str1, str2);
	return 0;
}
