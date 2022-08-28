#include<stdio.h>

int n;

int main(){
    int k,t;
    scanf("%d %d %d",&n,&k,&t);

    int index = 0;
    int thief = t-1;
    int count = 1;

    while(1){
        index = (index + k)%n;

        if(index == 0){
            break;
        }else if(index == thief){
            count++;
            break;
        }else{
            count++;
        }
    }

    printf("%d",count);
}