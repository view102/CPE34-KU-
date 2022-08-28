#include<stdio.h>
#include<stdlib.h>

int main(){
    char stringofint[100000];
    char stringofint2[100000];
    scanf("%s",stringofint);
    scanf("%s",stringofint2);
    char i='z';
    int count=0,count2=0;
    while(i!='\0'){
        i=stringofint[count];
        //printf("%c\n",i);
        if(i=='\0'){
            break;
        }
        count++;
    }
    i='z';
    while(i!='\0'){
        i=stringofint2[count2];
        //printf("%c\n",i);
        if(i=='\0'){
            break;
        }
        count2++;
    }
    int *num=NULL;
    int *num2=NULL;
    num = (int *)malloc(sizeof(int)*count);
    num2 = (int *)malloc(sizeof(int)*count2);
    int j,k;
    for (k=0,j=count-1;k<count;j--,k++){
        //printf("%c\n",stringofint[j]);
        num[k] = stringofint[j]-'0';
        //printf("--%d\n",num[k]);
    }
    for (k=0,j=count2-1;k<count2;j--,k++){
        //printf("%c\n",stringofint[j]);
        num2[k] = stringofint2[j]-'0';
        //printf("--%d\n",num[k]);
    }
    //printf("%d",num[1]+num2[1]);
    int *result=NULL,n,m;
    if (count>count2){
        n=count;
        m=count2;
    }else{
        n=count2;
        m=count;
    }
    result = (int *)malloc(sizeof(int)*(n));
    int x=0;
    for (j=0;j<n;j++){
        int sum=0;
        if (j<m){
            sum = num[j]+num2[j]+x;
            if(j==n-1){
                result[j]=sum;
                continue;
            }
            if (sum>=10){
                sum = sum%10;
                x=1;
            }else{
                x=0;
            }
            result[j]=sum;
        }else{
            if (count>count2){
                sum=num[j]+x;
                if(j==n-1){
                    result[j]=sum;
                    continue;
                }
                if (sum>=10){
                    sum = sum%10;
                    x=1;
                }else{
                    x=0;
                }
                result[j]=sum;
            }else{
                sum=num2[j]+x;
                if(j==n-1){
                    result[j]=sum;
                    continue;
                }
                if (sum>=10){
                    sum = sum%10;
                    x=1;
                }else{
                    x=0;
                }
                result[j]=sum;
            }
        }
    }
    for (j=n-1;j>=0;j--){
        printf("%d",result[j]);
    }
    return 0;
}
