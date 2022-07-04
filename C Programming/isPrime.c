#include<stdio.h>
#include<math.h>

int isPrime(int n);

int main(){
    int n;
    scanf("%d",&n);
    int result=isPrime(n);
    printf("%d",result);
}

int isPrime(int n){
    int i;
    if (n==1){
        return 0;
    }else if(n==2){
        return 1;
    }else{
        for (i=2;i<sqrt(n);i++){
            if (n%i==0){
                return 0;
            }
        }
        return 1;
    }
}