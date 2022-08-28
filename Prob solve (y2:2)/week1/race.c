#include<stdio.h>

long n;

int main(){
    long k,i;
    long speedest = 1000000000;
    long index_speedest;
    scanf("%ld %ld",&n,&k);

    long speed[n];
    for(i = 0; i < n; i++){
        scanf("%ld",&speed[i]);
        //printf("%ld : %d\n",speedest,speed[i]);
        if(speedest > speed[i]){
            speedest = speed[i];
            index_speedest = i;
        }
    }

    long count = n;
    for(i = 0; i < n; i++){
        //printf(" [%ld] : [%ld] \n",speedest*k,speed[i]*(k-1));
        if((speedest*k) <= (speed[i]*(k-1))){
            count--;
        }
    }
    //printf("%ld\n",speedest);
    /*int count = n;
    for(i = 2; i <= k; i++){
        for(int j = 0; j < n; j++){
            if((j == index_speedest) || (avaliable[j] == 0)){
                continue;
            }
            if((speedest*i) <= (speed[j]*(i-1))){
                avaliable[j] = 0;
                count--;
            }
        }
    }*/

    printf("%ld\n",count);
}