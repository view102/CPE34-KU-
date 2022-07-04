#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *s = NULL;
    char x[] = "HELLO";

    s = x;
    printf("%d",strlen(s));
}