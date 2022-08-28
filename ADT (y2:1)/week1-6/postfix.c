#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    float* arr;
    int count;
}list_t;

list_t create(int n){
    list_t list = {NULL,0};
    list.arr = (float*)malloc(sizeof(float)*n);
    return list;
}

void append(list_t* list, char num){
    list->arr[list->count] = (float) num - '0';
    list->count++;
}

void calcurate(list_t* list, char op){
    float x,y,sum;
    x = list->arr[list->count - 2];
    y = list->arr[list->count - 1];
    //printf("x : %f , y : %f\n",x,y);
    if (op == '+'){
        sum = x+y;
    }else if (op == '-'){
        sum = x-y;
    }else if (op == '*'){
        sum = x*y;
    }else if (op == '/'){
        sum = x/y;
    }
    list->count--;
    list->arr[list->count - 1] = sum;
    //printf("sum : %f\n",sum);
}

int main(){
    int n,i;
    char postf[10000];
    scanf("%d %s",&n,postf);
    list_t l = create(n);
    for (i=0;i<n;i++){
        if (postf[i] == '+' || postf[i] == '-' || postf[i] == '*' || postf[i] == '/'){
            calcurate(&l,postf[i]);
        }else{
            append(&l,postf[i]);
        }
    }
    printf("%.2f",(float)l.arr[0]);
}