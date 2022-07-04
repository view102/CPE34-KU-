#include<stdio.h>

int main(){
    int x,y;
    char op;
    scanf("%d %c %d",&x,&op,&y);
    if (op == '+'){
        int result = x + y;
        printf("%d",result);
    } else if (op == '-') {
        int result = x - y;
        printf("%d",result);
    } else if (op == '*') {
        int result = x * y;
        printf("%d",result);
    } else if (op == '%') {
        int result = x % y;
        printf("%d",result);
    } else if (op == '/') {
        float result = (float) x / y;
        printf("%.2f",result);
    } else {
        printf("Unknown Operator");
    }
    return 0;
}