#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100000

int main(){
    char num1[MAX],num2[MAX],tmp[MAX],result[MAX];
    int count=0,i,tod=0,minus=0;
    scanf("%s",num1);
    scanf("%s",num2);
    if(strlen(num2)>strlen(num1)){
        minus = 1;
        strcpy(tmp,num1);
        strcpy(num1,num2);
        strcpy(num2,tmp);
    }
    long a = strlen(num1)-1, b = strlen(num2)-1;
    //printf("a = %ld, b = %ld\n",a,b);
    for (i = a;i>=0;i--){
        int sum = 0;
        //printf("x = %c, y = %c\n",num1[a],num2[b]);
        //printf("b = %ld, a = %ld\n",b,a);
        if(b>=0){

            //printf("sum = %d\n",(num1[a]-'0') + (num2[b]-'0') +tod);
            if((num1[a]-'0')>=(num2[b]-'0')){
                sum = (num1[a]-'0') - (num2[b]-'0') -tod;
                //printf("sum = %d\n",sum);
                tod = 0;
            }else if((num1[a]-'0')==(num2[b]-'0') && a!=0 && b!=0){
                //printf("x = %c, y = %c\n",num1[a],num2[b]);
                //printf("HO\n");
                sum = 10 + (num1[a]-'0') - (num2[b]-'0') -tod;
                tod = 1;
            }else{
                sum = (num1[a]-'0') - (num2[b]-'0') -tod;
                //printf("sum = %d\n",sum);
                tod = 0;
            }
        }else if(a>=0){
            if((num1[a]-'0')>=tod){
                sum = (num1[a]-'0') - tod;
                tod = 0;
            }else{
                sum = 10 + (num1[a]-'0') - tod;
                tod = 1;
            }
        }
        printf("sum = %d\n",sum);
        result[count]=abs(sum)+'0';
        if(i==0 && tod==1){
            //printf("tod = %c done\n",tod+'0');
            count++;
            result[count]='-';
            //printf("count = %d done\n",count);
            break;
        }
        //printf("count = %d, tod = %d\n",count,tod);
        count++;
        a--;
        b--;
    }
    if (minus && result[count]!='-'){
        printf("minus\n");
        count++;
        result[count]='-';
    }
    for(i=count;i>=0;i--){
        printf("%c",result[i]);
    }
    return 0;
}