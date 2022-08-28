#include<stdio.h>
#include<stdlib.h>

int n,m;

typedef struct g{
    int name;
    int visit;
    int s;
    struct g *link;
}g_t;

typedef struct node{
    int name;
    struct node* next;
}node_t;

node_t* push(node_t* s, int name){
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->name = name;
    tmp->next = NULL;
    if(s == NULL){
        s = tmp;
        return s;
    }
    tmp->next = s;
    return tmp;
}

int pop(node_t** s){
    if(*s==NULL){
        return -1;
    }else{
        node_t* tmp = *s;
        *s = (*s)->next;
        int name = tmp->name;
        free(tmp);
        return name;
    }
}

g_t* createnode(int name){
    g_t *tmp = (g_t*)malloc(sizeof(g_t));
    tmp->name = name;
    tmp->visit = 0;
    tmp->s = 0;
    tmp->link = NULL;
    return tmp;
}

g_t** linking(g_t** graph, int n1, int n2){
    g_t* tmp1 = graph[n1];
    while(tmp1->link!=NULL){
        tmp1 = tmp1->link;
    }
    tmp1->link = createnode(n2);
    return graph;
}

void printg(g_t** graph, int n){
    int i;
    for(i=0;i<n;i++){
        printf("node : %d, ",graph[i]->name);
        g_t* tmp = graph[i]->link;
        while(tmp!=NULL){
            printf("link to %d, ",tmp->name);
            tmp = tmp->link;
        }
        printf("\n");
    }
}

node_t* findstack(g_t** gp, int n){
    node_t* stackhold=NULL;
    node_t* stackpop=NULL;
    node_t* fstack=NULL;
    for(int i = 0;i<n;i++){
        if(gp[i]->visit == 1){
            continue;
        }else{
            stackpop = push(stackpop,i);
            while(stackpop != NULL){
                int indexpop = pop(&stackpop);
                printf("pop : %d \n",indexpop);
                gp[indexpop]->visit = 1;
                g_t* tmp = gp[indexpop]->link;
                while(tmp!=NULL){
                    if(gp[tmp->name]->visit == 1){
                        if(gp[indexpop]->s == 0){
                            fstack = push(fstack,indexpop);
                            gp[indexpop]->s = 1;
                        }
                    }else{
                        stackpop = push(stackpop,tmp->name);
                    }
                    stackhold = push(stackhold,tmp->name);
                    tmp = tmp->link;
                }
            }
        }
    }
    while(stackhold != NULL){
        int holdpop = pop(&stackhold);
        if(gp[holdpop]->s == 0){
            fstack = push(fstack,holdpop);
            gp[holdpop]->s = 1;
        }
    }
    return fstack;
}

void prints(node_t* s){
    while(s!=NULL){
        printf("%d ",s->name);
        s = s->next;
    }
    printf("\n");
}

int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    g_t** graph = (g_t**)malloc(sizeof(g_t*)*n);
    g_t** tgraph = (g_t**)malloc(sizeof(g_t*)*n);
    node_t* fstack = NULL;
    node_t* fstack2 = NULL;
    for (i=0;i<n;i++){
        graph[i] = createnode(i);
        tgraph[i] = createnode(i);
    }
    for (i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph = linking(graph,u,v);
        tgraph = linking(tgraph,v,u);
    }
    printg(graph,n);
    printf("\n");
    printg(tgraph,n);
    fstack = findstack(graph,n);
    printf("\n");
    prints(fstack);
}