#include<stdio.h>
#include<string.h>

char str[100];

int main(){
    scanf("%s",str);
    int len = strlen(str);
    //printf("%d",len);

    int i;
    int x = 0, y = 0;

    for(i = 0; i < len; i++){
        if(str[i] == 'N'){
            y++;
        }else if(str[i] == 'E'){
            x++;
        }else if(str[i] == 'S'){
            y--;
        }else if(str[i] == 'W'){
            x--;
        }else{
            x = 0;
            y = 0;
        }
    }

    printf("%d %d\n",x,y);
}