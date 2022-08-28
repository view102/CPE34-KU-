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

void insertion_sort(int list[], int n, int index){
    int i = index;
    if(index < n){
        while(i > 0){
            if (list[i] < list[i-1]){
                int tmp = list[i];
                list[i] = list[i-1];
                list[i-1] = tmp;
            }
            i--;
        }
        //printlist(list,n);
        insertion_sort(list,n,index+1);
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

void printg(g_t** graph){
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

node_t* dfs(int i,g_t** gp,node_t* fstack){
    //printf("%d ",i);
    gp[i]->visit = 1;
    g_t* tmp = gp[i]->link;
    while(tmp!=NULL){
        if(gp[tmp->name]->visit == 0){
            fstack = dfs(tmp->name,gp,fstack);
        }
        tmp = tmp->link;
    }

    fstack = push(fstack,i);
    return fstack;
}

int dfs2(int i,g_t** gp, int countg, int group[]){
    //printf("%d ",i);

    group[countg] = i;
    countg++;

    gp[i]->visit = 1;

    g_t* tmp = gp[i]->link;
    while(tmp!=NULL){
        if(gp[tmp->name]->visit == 0){
            countg = dfs2(tmp->name,gp,countg,group);
        }
        tmp = tmp->link;
    }
    return countg;
}

void prints(node_t* s){
    while(s!=NULL){
        printf("%d ",s->name);
        s = s->next;
    }
    printf("\n");
}

int main(){
    int i;
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

    /*printg(graph);
    printf("\n");
    printg(tgraph);
    printf("\n");*/

    for(i=0;i<n;i++){
        if(graph[i]->visit == 0){
            fstack = dfs(i,graph,fstack);
        }
    }

    /*printf("\n");
    prints(fstack);
    printf("\n");*/

    int group[n+1],ans[n+1],count_a=0;
    int count_g=0;

    while(n--){
        int index = pop(&fstack);
        count_g = 0;
        if(tgraph[index]->visit == 1){
            continue;
        }
        count_g = dfs2(index,tgraph,count_g,group);

        for(i=0;i<count_g;i++){
            //printf("%d ",group[i]);
        }
        //printf("count : %d\n",count_g);

        if(count_a<count_g){
            count_a = count_g;
            for(i=0;i<count_g;i++){
                ans[i] = group[i];
            }
        }
    }
    /*for(i=0;i<count_a;i++){
        printf("%d ",ans[i]);
    }*/

    insertion_sort(ans,count_a,1);

    //printf("\n");
    for(i=0;i<count_a;i++){
        printf("%d ",ans[i]);
    }
}