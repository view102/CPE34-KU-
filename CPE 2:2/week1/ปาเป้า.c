#include<stdio.h>
#include<math.h>

int main(){
    int N;
    int sum = 0;
    scanf("%d",&N);
    for (int i = 0 ; i < N ; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        float range = sqrt((x*x)+(y*y));
        int score;
        if(range <= 2){
            score = 5;
        }else if(range <= 4){
            score = 4;
        }else if(range <= 6){
            score = 3;
        }else if(range <= 8){
            score = 2;
        }else if(range <= 10){
            score = 1;
        }else{
            score = 0;
        }
        //printf("score = %d\n",score);
        sum += score;
    }
    printf("%d",sum);
}