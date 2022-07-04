#include<stdio.h>

int main(void){
    char array_m[12][10]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year,month;
    printf("Enter year: ");
    scanf("%d",&year);
    printf("Enter month: ");
    scanf("%d",&month);
    printf("====================\n");
    printf("%s %d\n",array_m[month-1],year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int i;
    int start,day=1,time=0;
    int count=0;
    for (i=year-1;i>=1990;i--){
        //printf("%d\n",i);
        if ((i%4==0 && i%100!=0) || i%400==0){
            day+=366;
        } else {
            day+=365;
        }
        //printf("%d\n",day);
        time++;
    }
    //printf("%d %d\n",day,time);
    int m[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    if (year%4==0 && year%100!=0 || year%400==0){
        m[1] = 29;
    } else {
        m[1] = 28;
    }
    for (i=0; i<month-1; i++){
        day+=m[i];
        //printf("test\n");
    }
    //printf("%d\n",day);
    start=(day%7);
    //printf("%d\n",start);
    while(1){
        if(start!=-1){
            for (i=0;i<7;i++){
                if(i==0 && i!=start){
                    printf("  ");
                    printf(" ");
                    count++;
                    continue;
                }
                count++;
                if (i==start){
                    start=-1;
                    break;
                } else {
                    printf("   ");
                    printf(" ");
                }
                
            }
        }
        for (i=1;i<=m[month-1];i++){
            if (count==1){
                printf("%3d",i);
                count++;
                continue;
            }
            printf("%4d",i);
            if (count==7){
                count=0;
                printf("\n");
            }
            count++;

        }
        break;
    }
    return 0;
}