#include<stdio.h>

int main(){
    int new,old,cost,N;
    scanf("%d %d %d %d",&new,&old,&cost,&N);
    int day = (cost*1000)%(N*(old-new)) != 0 ? ((cost*1000)/(N*(old-new)))+1 : (cost*1000)/(N*(old-new));
    printf("%d",day);
    return 0;
}