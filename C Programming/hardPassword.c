#include<stdio.h>
#include<stdlib.h>
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
    list->count++;
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
    int result;
    char type = 'x';
    list_t l = create();
    while(1){
        scanf("%c",&pass);
        if(pass == 'x'){
            type = 'y';
            continue;
        }
        if (pass == 'y'){
            break;
        }
        if (type == 'x'){
            append(&l,pass);
        }else{
            result = check(&l,pass);
        }
        if (result == 0){
            break;
        }
        //printf("l.arr = %c\n",l.arr[l.count]);
    }
    printf("%d",result);
    return 0;
}