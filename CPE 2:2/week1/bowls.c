#include<stdio.h>

int main(){
    int max = -1;
    int s1[100010], s2[310];
    int n;
    for(int j = 0; j < 310; j++){
        s2[j] = 0;
    }
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int size;
        scanf("%d",&size);
        s1[i] = size;
        s2[size-1] += 1;
        if(max < s2[size-1]){
            max = s2[size-1];
        }
    }
    printf("%d\n",max);
}