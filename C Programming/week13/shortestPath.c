#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    int visit;
    int weight;
    struct node *link;
}node_t;

typedef struct q{
    int data;
    struct q *next;
}q_t;

q_t* enqueue(q_t* q , int num){
    q_t* tmp = (q_t*)malloc(sizeof(q_t));
    tmp->data = num;
    tmp->next = NULL;
    if(q==NULL){
        q = tmp;
        return q;
    }
    q_t* last=q;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = tmp;
    return q;
}

int dequeue(q_t** start){
    q_t* tmp = (*start);
    (*start) = (*start)->next;
    return tmp->data;
}

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
    return graph;
}

q_t* sortq(q_t* q){
    int min=999999;
    q_t* tmp = q;
    while(tmp!=NULL){
        if(tmp->data < min){
            min = tmp->data;
        }
    }
    q_t* start = q->data;
    tmp = q->next;
    q->data = min;
    while(tmp!=NULL){
        if(tmp->data == min){
            tmp->data = start;
        }
        tmp = tmp->next;
    }
    return q;
}

int shortpath(node_t** graph, int n1, int n2, int n){
    int i;
    for(i=0;i<n;i++){
        if(graph[i]->num == n1){
            graph[i]->weight = 0;
        }else{
            graph[i]->weight = 100000;
        }
    }
    q_t* q = NULL;
    q = enqueue(q, graph[n1]->num);
    while(q!=NULL){
        int index = dequeue(&q);
        node_t* tmp = graph[index]->link;
        while(tmp!=NULL){
            int l;
            if (graph[tmp->num]->visit == 0){
                q = enqueue(q, tmp->num);
                if(graph[tmp->num]->weight == 100000){
                    l = tmp->weight;
                }else{
                    l = tmp->weight + graph[index]->weight;
                }
                if(l<graph[tmp->num]->weight){
                    graph[tmp->num]->weight = l;
                }
                graph[tmp->num]->visit = 1;
            }
            tmp = tmp->link;
        }
        q = sortq(q);
    }
    return graph[n2]->weight;
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
    for(i=0;i<p;i++){
        scanf("%d %d",&node1,&node2);
        printf("%d\n",shortpath(graph,node1,node2,n));
    }
    return 0;
}