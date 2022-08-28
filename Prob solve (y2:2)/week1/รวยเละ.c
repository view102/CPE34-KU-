#include<stdio.h>

int main(){
    int n;
    int sum = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int cost;
        scanf("%d",&cost);
        if(cost >= 0){
            sum += cost;
        }
    }
    printf("%d\n",sum);
}