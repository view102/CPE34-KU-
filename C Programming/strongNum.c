#include<stdio.h>

long fac(long a){
    if (a==1 || a==0){
        return 1;
    }
    return a * fac(a-1);
}

int main(void){
    int time;
    scanf("%d",&time);
    int i;
    for (i=0;i<time;i++){
        long n=0;
        scanf("%ld",&n);
        //printf("%ld",fac(n));
        long result=0;
        while(1){
            long num=--n;
            //printf("%ld %ld\n",num,n);
            long sum=0;
            long j;
            for (j=n;j!=0;j/=10){
                //printf("%ld\n",i);
                sum += fac(j%10);
                //printf("finish\n");
            }
            if (sum == num){
                result = sum;
                break;
            }
        }
        printf("%ld\n",result);
    }
    return 0;
}