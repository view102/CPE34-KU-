#include<stdio.h>
#include<math.h>

long area(long w,long l);

int main(){
    long m,n;
    scanf("%ld %ld",&m,&n);
    long result;
    result=area(m,n);
    printf("%ld",result);
    return 0;
}

long area(long w,long l){
    long i,max,a,x;
    max=-1;
    if (w==0 || l==0){
        return 0;
    }else if(w==1){
        return l;
    }else if(l==1){
        return w;
    }else{
        if (w<l){
            x=w;
        }else{
            x=l;
        }
        for (i=0;i<=x;i++){
            a=pow(2,i);
            if (a>x){
                break;
            }
            if (a>max){
                max=a;
            }
        }
        return 1 + area(w-max,l) + area(max,l-max);
    } 
}
// O(n * log n)