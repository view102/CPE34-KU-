#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t* append(node_t** start, node_t** last, int num){
    node_t* node=(node_t *)malloc(sizeof(node_t));
    node->data=num;
    node->next=NULL;
    if (*start==NULL){
        *start=node;
        *last=*start;
        return *start;
    }
    (*last)->next = node;
    *last=node;
    return *start;
}

void get(node_t* start, int num){
    int i;
    node_t* d=start;
    for(i=0;i<num;i++){
        //printf("--\n");
        d=d->next;
    }
    printf("%d\n",d->data);
}

void show(node_t* start){
    int first=1;
    node_t* d=start;
    while(1){
        if (d==NULL){
            printf("\n");
            break;
        }
        if (first==1){
            printf("%d",d->data);
            d=d->next;
            first=0;
        }else{
            printf(" %d",d->data);
            (d)=(d)->next;
        }
    }
}

node_t* reverse(node_t** start, node_t** last){
    node_t* tmp=NULL;
    node_t* keep = *start;
    node_t* keep2 = (*start)->next;
    int first=1;
    while(1){
        //printf("--\n");
        tmp = keep2;
        if (keep2->next == NULL){
            tmp->next = keep;
            break;
        }
        //printf("--\n");
        if (first==1){
            keep->next = NULL;
            first=0;
        }
        //printf("--\n");
        //printf("--\n");
        keep2 = tmp->next;
        tmp->next = keep;
        //printf("--\n");
        *start = keep2;
        //printf("--\n");
        keep = tmp;
    }
    return tmp;
}

node_t* cut(node_t** start, node_t** last, int n1, int n2){
    int i;
    node_t* tmp=NULL;
    node_t* keep=NULL;
    node_t* startnode=NULL;
    for (i=0;i<n1;i++){
        tmp = *start;
        *start = (*start)->next;
        //free(tmp);
    }
    startnode = *start;
    for (i=0;i<n2-n1;i++){
        *start = (*start)->next;
    }
    tmp = *start;
    /*while(1){
        if(tmp->next == NULL){
            free(tmp);
        }
        keep = tmp->next;
        free(tmp);
        tmp = keep;
    }*/
    (*start)->next=NULL;
    return startnode;
}

int main(void){
    node_t* startNode;
    node_t* lastNode;
    int n,i,num,num1;
    char command;

    startNode = NULL;
    lastNode = NULL;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        //printf("Scan");
        scanf(" %c", &command);
        if(command=='A'){
            scanf(" %d",&num);
        }else if(command=='G'){
            scanf(" %d",&num);
        }else if(command=='C'){
            scanf(" %d %d",&num,&num1);
        }
        switch (command) {
            case 'A':
                startNode = append(&startNode,&lastNode,num);
                break;
            case 'G':
                get(startNode,num);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(&startNode,&lastNode);
                break;
            case 'C':
                startNode = cut(&startNode,&lastNode,num,num1);
                break;
            default:
                break;
        }
    }
    return 0;
}