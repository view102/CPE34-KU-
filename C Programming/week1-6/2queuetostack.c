#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data;
    struct queue *next; 
}queue_t;

queue_t* enqueue(queue_t* q , int num){
    queue_t* tmp = (queue_t*)malloc(sizeof(queue_t));
    tmp->data = num;
    tmp->next = NULL;
    if(q==NULL){
        q = tmp;
        return q;
    }
    queue_t* last=q;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = tmp;
    return q;
}

int dequeue(queue_t** q){
    int x;
    x = (*q)->data;
    (*q) = (*q)->next;
    return x;
}

void push(queue_t** q1, queue_t** q2 , int num){
    if (*q1 == NULL){
        *q2 = enqueue(*q2,num);
    }
    while((*q1) != NULL){
        *q2 = enqueue(*q2, dequeue(&(*q1)));
    }
    *q1=enqueue(*q1,num);
    while((*q2)!=NULL){
        *q1 = enqueue(*q1, dequeue(&(*q2)));
    }
}

int pop(queue_t** q){
    int x = (*q)->data;
    *q = (*q)->next;
    return x;
}

int main(){
    queue_t *q1 = NULL, *q2 = NULL;
    int n,i,val,rp;
    char command;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&command);
        switch(command){
            case 'P':
                scanf(" %d",&val);
                push(&q1,&q2,val);
                break;
            case 'p':
                rp = pop(&q1);
                printf("%d\n",rp);
                break;
            default:
                break;
        }
    }
    return 0;
}