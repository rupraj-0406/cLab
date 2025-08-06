#include<stdio.h>

int main(){
    int glu,age,flag=0;//ND=flag=0, D=flag=1
    float hem,bmi;
    scanf("%d", &glu);
    scanf("%d", &age);
    if(glu<52){
        if(age<52)flag=0;
        else{
            scanf("%f",&hem);
            if(hem<6.4)flag=0;
            else flag=1;
        }
    }
    else{
        if(age<50){
            scanf("%f",&bmi);
            if(bmi<34)flag=0;
            else{
                if(glu<151)flag=0;
                else flag=1;
            }
        }else{
            if(glu<160){
                scanf("%f",&hem);
                if(hem<6.5)flag=0;
                else flag=1;
            }
            else{
                flag=1;
            }
        }
    }
    if(flag==0)printf("ND");
    else printf("D");
    return 0;
}