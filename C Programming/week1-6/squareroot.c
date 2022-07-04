#include<stdio.h>
#include<math.h>
double predictroot(double a, double b){
    double x = (b+(a/b))/2; 
    return x;
}

int main(void){
    double n,i;
    scanf("%lf %lf",&n,&i);
    //printf("%.10lf",predictroot(n,i));
    while(1){
        double result = predictroot(n,i);
        printf("%.10lf %.10lf %.10lf\n",result,i,fabs(result-i));
        if(fabs(result-i)<=0.0000000001){
            break;
        }
        i = result;
    }
    //printf("%.10lf%.10lf",n,i);
    printf("%.10lf",i);
    return 0;
}