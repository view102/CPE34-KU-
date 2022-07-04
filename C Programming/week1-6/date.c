#include<stdio.h>

int main(){
    int m[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    int dd,mm,yy;
    int day=0;
    scanf("%d/%d/%d",&dd,&mm,&yy);
    if (yy%4==0 && yy%100!=0 || yy%400==0){
        m[1] = 29;
    } else {
        m[1] = 28;
    }
    //printf("%d",m[1]);
    int i;
    for (i=0; i<mm-1; i++){
        day+=m[i];
        //printf("%d\n",m[i]);
    }
    day+=dd;
    //printf("%d %d %d\n",dd,mm,yy);
    printf("%d",day);
    return 0;
}