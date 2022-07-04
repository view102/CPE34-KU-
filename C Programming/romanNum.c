#include<stdio.h>

char roman(int n);

int main(){
    int time;
    //printf("Hello");
    scanf("%d",&time);
    int i;
    for (i=0; i<time; i++){
        int n;
        //printf("test");
        scanf("%d",&n);
        roman(n);
    }
    return 0;
}

char roman(int n){
    if(n>=1000){
        n=n-1000;
        printf("M");
        return roman(n);
    }else if(n>=900){
        n=n-900;
        printf("CM");
        return roman(n);
    }else if(n>=500){
        n=n-500;
        printf("D");
        return roman(n);
    }else if(n>=400){
        n=n-400;
        printf("CD");
        return roman(n);
    }else if(n>=100){
        n=n-100;
        printf("C");
        return roman(n);
    }else if(n>=90){
        n=n-90;
        printf("XC");
        return roman(n);
    }else if(n>=50){
        n=n-50;
        printf("L");
        return roman(n);
    }else if(n>=40){
        n=n-40;
        printf("XL");
        return roman(n);
    }else if(n>=10){
        n=n-10;
        printf("X");
        return roman(n);
    }else if(n>=9){
        n=n-9;
        printf("IX");
        return roman(n);
    }else if(n>=5){
        n=n-5;
        printf("V");
        return roman(n);
    }else if(n>=4){
        n=n-4;
        printf("IV");
        return roman(n);
    }else if(n>=1){
        n=n-1;
        printf("I");
        return roman(n);
    }else{
        printf("\n");
        return 0;
    }
    printf("\n");
    return 0;
}