#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int dataint;
    double datadouble;
    char datastring[10];
    int type;
} node_t;

typedef struct list {
    node_t node;
    struct list *next;
} list_t;

list_t* append(list_t** start, list_t** last, int type, int num, double dou, char str[], int* pcount){
    list_t* listnode=(list_t *)malloc(sizeof(list_t));
    listnode->next=NULL;
    if(type == 0){
        listnode->node.type=0;
        listnode->node.dataint=num;
    }else if (type == 1){
        listnode->node.type=1;
        listnode->node.datadouble=dou;
    }else{
        listnode->node.type=2;
        //strcpy(listnode->node.datastring,str);
        strncat(listnode->node.datastring,str,10);
    }
    if (*start == NULL){
        *start = listnode;
        *last = *start;
        (*pcount)++;
        return *start;
    }
    (*last)->next = listnode;
    *last = listnode;
    (*pcount)++;
    return *start;
}

void get(list_t* start, int num){
    int i;
    list_t* d=start;
    for(i=0;i<num;i++){
        //printf("--\n");
        d=d->next;
    }
    if (d->node.type == 0){
        printf("%d\n",d->node.dataint);
    }else if(d->node.type == 1){
        printf("%.6lf\n",d->node.datadouble);
    }else{
        printf("%s\n",d->node.datastring);
    }
}

void show(list_t** start){
    list_t* d= *start;
    while(d != NULL){
        if(d->node.type == 0){
            printf("%d ",d->node.dataint);
        }else if(d->node.type == 1){
            printf("%.6lf ",d->node.datadouble);
        }else{
            printf("%s ",d->node.datastring);
        }   
        if (d->next == NULL){
            break;
        }
        d=d->next;
    }
    printf("\n");
}

list_t* show_reverse(list_t** start){
    list_t* tmp=*start;
    list_t* keep = NULL;
    list_t* keep2 = NULL;
    int first=1;
    while(1){
        if (tmp->next == NULL){
            tmp->next=keep;
            break;
        }
        keep2 = tmp->next;
        tmp->next = keep;
        keep = tmp;
        tmp = keep2;
    }
    return tmp;
}

void insert(list_t** start, list_t** last, int pos, int type, int num, double dou, char str[10], int* pcount){
    int i;
    list_t* d= *start;
    list_t* listnode=(list_t *)malloc(sizeof(list_t));
    if(type == 0){
        listnode->node.type=0;
        listnode->node.dataint=num;
    }else if (type == 1){
        listnode->node.type=1;
        listnode->node.datadouble=dou;
    }else{
        listnode->node.type=2;
        //strcpy(listnode->node.datastring,str);
        strncpy(listnode->node.datastring,str,10);
    }
    for(i=0;i<pos;i++){
        //printf("--\n");
        d=d->next;
    }
    if (d->next == NULL){
        d->next=listnode;
        listnode->next=NULL;
        *last = listnode;
    } else {
        listnode->next=d->next;
        d->next = listnode;
    }
    (*pcount)++;
}

list_t* delete(list_t** start, list_t** last, int pos, int* pcount){
    int i;
    list_t* d = *start;
    list_t* tmp = NULL;
    list_t* keep = d;
    //printf("-----1\n");
    if(*pcount == 1 && pos == 0){
        //printf("-----2\n");
        (*pcount)--;
        //printf("-----3\n");
        *last = NULL;
        return NULL;
    } 
    if (pos==0){
        return (*start)->next;
    }
    for(i=0;i<pos;i++){
        //printf("-----4\n");
        keep = d;
        //printf("-----5\n");
        d=d->next;
    } 
    if (pos == (*pcount)-1){
        *last = keep;
    }
    //printf("-----6\n");
    tmp = d;
    //printf("-----7\n");
    keep->next = d->next;
    //printf("-----8\n");
    //free(tmp);
    //printf("-----9\n");
    (*pcount)--;
    return *start;
}

list_t* change(list_t** start, int pos, int type, int num, double dou, char str[10]){
    int i;
    list_t* d = *start;
    for(i=0;i<pos;i++){
        d=d->next;
    }
    d->node.type=type;
    if (type == 0){
        d->node.dataint=num;
    }else if(type == 1){
        d->node.datadouble=dou;
    }else{
        strncpy(d->node.datastring,str,10);
    }
    return *start;
}

void is_empty(list_t* start){
    if(start==NULL){
        printf("Empty\n");
    }else{
        printf("Not Empty\n");
    }
}

void length(list_t* start){
    int count=0;
    if (start == NULL){
        printf("0\n");
    }else{
        while (1){
            if(start->next == NULL){
                count++;
                break;
            }
            count++;
            start = start->next;
        }
        printf("%d\n",count);
    }
}

int main(void){
    list_t* startNode;
    list_t* lastNode;
    list_t* tmp;
    int count=0;
    int n,i,num,num1,type,pos;
    char command;
    char string[10];
    double dou;

    startNode = NULL;
    lastNode = NULL;
    tmp = NULL;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        //printf("Scan");
        scanf(" %c", &command);
        if(command=='A'){
            scanf(" %d",&type);
            if (type == 0){
                scanf(" %d",&num);
            }else if (type == 1){
                scanf(" %lf",&dou);
            }else{
                scanf(" %s",string);
            }
        }else if(command=='G'){
            scanf(" %d",&num);
        }else if(command=='I' || command=='C'){
            scanf(" %d %d",&pos,&type);
            if (type == 0){
                scanf(" %d",&num);
            }else if (type == 1){
                scanf(" %lf",&dou);
            }else{
                scanf(" %s",string);
            }
        }else if(command=='D'){
            scanf(" %d",&pos);
        }
        switch (command) {
            case 'A':
                if (type == 0){
                    append(&startNode,&lastNode,type,num,0,"00",&count);
                } else if (type == 1){
                    append(&startNode,&lastNode,type,0,dou,"00",&count);
                }else{
                    append(&startNode,&lastNode,type,0,0,string,&count);
                }
                break;
            case 'G':
                get(startNode,num);
                break;
            case 'S':
                show(&startNode);
                break;
            case 'R':
                startNode = show_reverse(&startNode);
                show(&startNode);
                startNode = show_reverse(&startNode);
                break;
            case 'I':
                if (type == 0){
                    insert(&startNode,&lastNode,pos,type,num,0,"00",&count);
                } else if (type == 1){
                    insert(&startNode,&lastNode,pos,type,0,dou,"00",&count);
                }else{
                    insert(&startNode,&lastNode,pos,type,0,0,string,&count);
                }
                break;
            case 'D':
                startNode = delete(&startNode,&lastNode,pos,&count);
                break;
            case 'C':
                if (type == 0){
                    startNode = change(&startNode,pos,type,num,0,"00");
                } else if (type == 1){
                    startNode = change(&startNode,pos,type,0,dou,"00");
                }else{
                    startNode = change(&startNode,pos,type,0,0,string);
                }
                break;
            case 'E':
                is_empty(startNode);
                break;
            case 'L':
                length(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}