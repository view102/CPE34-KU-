#include<stdio.h>

int main(){
    int x,y,z;
    scanf("%d %d %d\n",&x,&y,&z);
    char hungry,sick;
    scanf("%c %c",&hungry,&sick);
    //printf("%c %c",hungry,sick);
    int meal = x;
    if (hungry == 'Y' || hungry == 'y'){
        meal += y;
    }
    if (sick == 'Y' || sick == 'y'){
        meal = meal%z != 0 ? (meal/z)+1 : meal/z;
    }
    printf("%d",meal);
    return 0;
}