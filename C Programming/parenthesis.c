#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000

typedef struct list{
    char* arr;
    int count;
}list_t;

list_t create(){
    list_t l = {NULL,0};
    l.arr = (char*)malloc(sizeof(char)*MAXSIZE);
    return l;
}

list_t append(list_t* list, char p){
    //printf("p append = %c\n",p);
    list->arr[list->count] = p;
    //printf("list->arr = %c\n",list->arr[list->count]);
    (list->count)++;
    return *list;
}

int check(list_t* list, char p){
    int ans;
    //printf("p = %c\n",p);
    //printf("list[] = %c\n",list->arr[list->count]);
    //printf("list->count = %d\n",list->count);
    if (p == ']'){
        if (list->arr[list->count - 1] == '['){
            (list->count)--;
            ans = 1;
        }else{
            ans = 0;
        }
    }else if(p == '}'){
        if (list->arr[list->count - 1] == '{'){
            (list->count)--;
            ans = 1;
        }else{
            ans = 0;
        }
    }else if(p == ')'){
        if (list->arr[list->count - 1] == '('){
            (list->count)--;
            ans = 1;
        }else{
            ans = 0;
        }
    }
    return ans;
}

int main(){
    int i;
    long n;
    int result = 1;
    char prt[MAXSIZE];
    list_t list=create();
    scanf("%ld %s",&n,prt);
    for(i=0;i<n;i++){
        //printf("prt = %c : %d\n",prt[i],result);
        if (prt[i] == '[' || prt[i] == '(' || prt[i] == '{'){
            list = append(&list,prt[i]);
            //printf("list.arr[] = %c\n",list.arr[list.count - 1]);
        }else{
            result = check(&list,prt[i]);
        }
        //printf("count = %d\n",list.count);
        //if (result == 0){
        //    break;
        //}
    }
    if (list.count != 0){
        result = 0;
    }
    printf("%d",result);
    //printf("%c",prt[1]);
}