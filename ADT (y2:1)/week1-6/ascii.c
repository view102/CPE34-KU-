#include<stdio.h>

int main(){
    char firstletter,secondletter;
    scanf("%c %c",&firstletter,&secondletter);
    int x = firstletter, y = secondletter;
    int diff = y>x ? y-x : x-y;
    printf("%d",diff);
    return 0;
}