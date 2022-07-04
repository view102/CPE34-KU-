#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100000

typedef struct list{
    char* arr;
    int count;
}list_t;

list_t create(){
    list_t l = {NULL,0};
    l.arr = (char*)malloc(sizeof(char)*MAXSIZE);
    return l;
}

void append(list_t* list, char p){
    list->arr[list->count] = p;
    (list->count)++;
}

int check(list_t* list, char y){
    int ans;
    if (list->arr[list->count - 1] == y){
        list->count--;
        ans = 1;
    }else{
        ans = 0;
    }
    return ans;
}

int main(){
    char pass;
    char word[MAXSIZE];
    int result,i;
    char type = 'x';
    list_t l = create();
    scanf("%s",word);
    int n = strlen(word);
    int starty = (n/2);
    for (i=0;i<(n/2)-1;i++){
        append(&l,word[i]);
    }
    for (i=starty;i<n-1;i++){
        result = check(&l,word[i]);
        if (result == 0){
            break;
        }
    }
    printf("%d",result);
    return 0;
}