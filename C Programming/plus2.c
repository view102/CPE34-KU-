#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100000

int main(){
    char num1[MAX],num2[MAX],tmp[MAX],result[MAX];
    int count=0,i,tod=0;
    scanf("%s",num1);
    scanf("%s",num2);
    if(strlen(num2)>strlen(num1)){
        strcpy(tmp,num1);
        strcpy(num1,num2);
        strcpy(num2,tmp);
    }
    long a = strlen(num1)-1, b = strlen(num2)-1;
    //printf("a = %ld, b = %ld\n",a,b);
    for (i = a;i>=0;i--){
        int sum = 0;
        if(b>=0){
            //printf("sum = %d\n",(num1[a]-'0') + (num2[b]-'0') +tod);
            sum = (num1[a]-'0') + (num2[b]-'0') +tod;
        }else if(a>=0){
            sum = (num1[a]-'0') + tod;
        }
        if(sum>=10){
            tod=1;
            sum = sum%10;
        }else{
            tod=0;
        }
        if(i==0 && tod==1){
            //printf("tod = %c done\n",tod+'0');
            count++;
            result[count]=tod+'0';
            //printf("count = %d done\n",count);
            break;
        }
        printf("sum = %d\n",sum);
        result[count]=sum+'0';
        //printf("count = %d, tod = %d\n",count,tod);
        count++;
        a--;
        b--;
    }
    for(i=count;i>=0;i--){
        printf("%c",result[i]);
    }
    return 0;
}