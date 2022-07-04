#include <stdio.h>
#include <stdlib.h>

void findStats(int n,int *numsp, int *maxip, int *minip, double *avgp){
    //find max and min
    int i;
    double sum=0;
    for (i=0;i<n;i++){
        sum+=numsp[i];
        if(i==0){
            *maxip = numsp[0];
            *minip = numsp[0];
            continue;
        }
        if (numsp[i]>*maxip){
            *maxip = numsp[i];
        }
        if (numsp[i]<*minip){
            *minip = numsp[i];
        }
    }
    *avgp = sum/n;
}

int main(){
    int n, i, maxi, mini;
    double avg;
    int* nums;
    scanf("%d",&n);
    nums = (int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d", nums+i);
    findStats(n, nums, &maxi, &mini, &avg);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}