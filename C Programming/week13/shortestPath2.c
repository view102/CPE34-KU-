#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    int visit;
    int weight;
    struct node *link;
}node_t;

node_t* createnode(int num, int w){
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->link = NULL;
    tmp->num = num;
    tmp->visit = 0;
    tmp->weight = w;
    return tmp;
}

node_t** creategraph(int n){
    int i;
    node_t** tmp = (node_t**)malloc(sizeof(node_t*)*n);
    for(i=0;i<n;i++){
        tmp[i] = createnode(i,0);
    }
    return tmp;
}

node_t** linking(node_t** graph, int n1, int n2, int w){
    node_t* tmp1 = graph[n1];
    node_t* tmp2 = graph[n2];
    while(tmp1->link!=NULL){
        tmp1 = tmp1->link;
    }
    while(tmp2->link!=NULL){
        tmp2 = tmp2->link;
    }
    tmp1->link = createnode(n2,w);
    tmp2->link = createnode(n1,w);
    tmp1 = tmp1->link;
    tmp2 = tmp2->link;
    tmp1->link = NULL;
    tmp2->link = NULL;
    return graph;
}

int findmin(node_t** graph, int n){
    int i,index;
    int min=999999;
    for(i=0;i<n;i++){
        if((graph[i]->weight < min) && (graph[i]->visit == 0)){
            min = graph[i]->weight;
            index = i;
        }
    }
    return index;
}

int check_visit(node_t** graph, int n){
    int i;
    int all = 0;
    for(i=0;i<n;i++){
        if(graph[i]->visit == 0){
            all = 1;
        }
    } 
    return all;
}

node_t** initial_graph(node_t** graph, int start, int n){
    int i;
    for(i=0;i<n;i++){
        if(graph[i]->num == start){
            graph[i]->weight = 0;
            graph[i]->visit = 0;
        }else{
            graph[i]->weight = 100000;
            graph[i]->visit = 0;
        }
    }
    return graph;
}

void printg(node_t** graph, int n){
    int i;
    for(i=0;i<n;i++){
        printf("node : %d, ",graph[i]->num);
        node_t* tmp = graph[i]->link;
        while(tmp!=NULL){
            printf("link to %d, ",tmp->num);
            tmp = tmp->link;
        }
        printf("\n");
    }
}

node_t** shortpath(node_t** graph, int n1, int n2, int n){
    int i;
    int check=1;
    int link=0;
    graph = initial_graph(graph,n1,n);
    node_t* start = graph[n1]->link;
    while(check){
        int l;
        int index = findmin(graph,n);
        //printg(graph,n);
        //printf("node : %d, w : %d\n",graph[index]->num,graph[index]->weight);
        node_t* tmp = graph[index]->link;
        while(tmp!=NULL){
            if(graph[tmp->num]->visit == 0){
                //printf("    link : %d, w : %d\n",tmp->num,tmp->weight);
                l = tmp->weight + graph[index]->weight;
                if(l<graph[tmp->num]->weight){
                    graph[tmp->num]->weight = l;
                }
            }
            tmp = tmp->link;
        }
        graph[index]->visit = 1;
        
        check = check_visit(graph,n);
    }
    return graph;
}

int main(){
    int n,m,p,i,u,v,w;
    scanf("%d %d %d",&n,&m,&p);
    node_t** graph = creategraph(n);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        graph = linking(graph,u,v,w);
    }
    int node1,node2;
    //printg(graph,n);
    for(i=0;i<p;i++){
        scanf("%d %d",&node1,&node2);
        graph = shortpath(graph,node1,node2,n);
        if(graph[node2]->weight==100000){
            graph[node2]->weight = -1;
        }
        printf("%d\n",graph[node2]->weight);
    }
    return 0;
}