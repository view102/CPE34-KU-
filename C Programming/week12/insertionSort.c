#include<stdio.h>
#include<stdlib.h>

void printlist(int* list, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

void insertion_sort(int* list, int n, int index){
    int i = index;
    if(index < n){
        while(i > 0){
            if (list[i] < list[i-1]){
                int tmp = list[i];
                list[i] = list[i-1];
                list[i-1] = tmp;
            }
            i--;
        }
        printlist(list,n);
        insertion_sort(list,n,index+1);
    }
}

int main(){
    int n,i,num;
    int *num_list;
    scanf("%d",&n);
    num_list = (int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++){
        scanf("%d",&num);
        num_list[i] = num;
    }
    insertion_sort(num_list,n,1);
}