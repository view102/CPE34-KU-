#include<stdio.h>

int main(){
    int now,time;
    scanf("%d %d",&now,&time);
    //printf("%d %d\n",now,time);
    int day = (time+now)/24;
    int timemeet = (time+now)%24;
    printf("%d %d",day,timemeet);
    return 0;
}