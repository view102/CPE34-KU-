#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int priority;
    char data[10000];
    struct node *left, *right;
} node_t;

typedef struct heap{
    struct node **array;
    int count;
} heap_t;

heap_t* createheap(heap_t* heap){
    heap_t* heapp = (heap_t*)malloc(sizeof(heap_t));
    heapp->array = (node_t**)malloc(sizeof(node_t*)*10000);
    heapp->count = 1;
    return heapp;
}

void swap(node_t** a, node_t** b){
    node_t* tmp = *a;
    *a = *b;
    *b = tmp;
}

node_t* newnode(char str[10000], int priority){
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->priority = priority;
    strcpy(tmp->data,str);
    return tmp;
}

void maintainheap(heap_t* heap, int index){
    int lower = index;
    int left = 2*index;
    int right = 2*index + 1;
    //printf("======1 %d\n",lower);
    if(left< heap->count && heap->array[left]->priority < heap->array[lower]->priority){
        //printf("======2\n");
        lower = left;
    }
    //printf("======3\n");
    if(right< heap->count && heap->array[right]->priority < heap->array[lower]->priority){
        //printf("======4\n");
        lower = right;
        //printf("======5\n");
    }
    //printf("======6\n");
    if(lower != index){
        //printf("======7\n");
        swap(&heap->array[lower],&heap->array[index]);
        //printf("======8\n");
        maintainheap(heap, lower);
        //printf("======9\n");
    }
}

void sort_priority(heap_t* heap, int value, int index){
    int index_parent = index/2;
    //printf("===1 pri : %d\n",value);
    if(heap->count != 1){
        int last = index;
        //printf("===2 parent pri : %d\n",heap->array[index_parent]->priority);
        while(heap->array[index_parent]->priority > value){
            //printf("===3\n");
            //printf("===5\n");
            char tmp[10000];
            //printf("===6\n");
            strcpy(tmp,heap->array[last]->data);
            int prio = heap->array[last]->priority;
            //printf("===7\n");
            strcpy(heap->array[last]->data,heap->array[index_parent]->data);
            heap->array[last]->priority = heap->array[index_parent]->priority;
            //printf("===8\n");
            strcpy(heap->array[index_parent]->data,tmp);
            heap->array[index_parent]->priority = prio;
            //printf("===9\n");
            last = index_parent;
            //printf("===10\n");
            index_parent = index_parent/2;
            //printf("===11\n");
            if (index_parent == 0){
                //printf("===12\n");
                break;
            }
        }
    }
}

void insert(heap_t* heap, char str[10000], int priority){
    int index_parent = heap->count/2;
    //printf("parent = %d\n",index_parent);
    if (heap->count == 1){
        //printf("---1\n");
        heap->array[heap->count] = newnode(str,priority);
        //printf("---2\n");
    }else{
        //printf("---3\n");
        heap->array[heap->count] = newnode(str,priority);
        //check priority
        //printf("---4\n");
        sort_priority(heap,priority,heap->count);
        //printf("---5\n");
    }
    //printf("---6\n");
    heap->count++;
}

node_t* delete(heap_t* heap){
    //printf("----1\n");
    node_t* tmp = heap->array[1];
    //printf("----2\n");
    heap->array[1] = heap->array[heap->count - 1];
    //printf("----3\n");
    heap->count--;
    //printf("----4\n");
    maintainheap(heap, 1);
    //printf("----5\n");
    return tmp;
}

void bfs(heap_t* heap){
    int i;
    for (i=1;i<heap->count;i++){
        printf("%s ",heap->array[i]->data);
    }
    printf("\n");
}

node_t* merge(node_t* left, node_t* right){
    //printf("------1\n");
    int sum = left->priority + right->priority;
    //printf("------2\n");
    char c[10000];
    strcpy(c,left->data);
    strcat(c,right->data);
    //printf("------3\n");
    node_t* tmp = newnode(c,sum);
    //printf("------4\n");
    tmp->left = left;
    //printf("------5\n");
    tmp->right = right;
    //printf("------6\n");
    return tmp;
}

void insertnode(heap_t* heap, node_t* sumnode){
    //printf("=1\n");
    heap->array[heap->count] = sumnode;
    //printf("=2\n");
    sort_priority(heap,sumnode->priority,heap->count);
    //printf("=3\n");
    heap->count++;
}

void printleaf(node_t* tree){
    if(tree == NULL){
        return;
    }
    printleaf(tree->left);
    if(tree->left == NULL && tree->right == NULL){
        printf("%s\n",tree->data);    
    }
    printleaf(tree->right);
}

int main(){
    int n,i,priority;
    char str[10000];
    heap_t* heap = NULL;
    heap = createheap(heap);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d",str,&priority);
        //printf("hi\n");
        insert(heap,str,priority);
    }
    bfs(heap);
    while(heap->count != 2){
        printf("-1 : ");
        bfs(heap);
        node_t* tmp1 = delete(heap);
        printf("-2 : ");
        bfs(heap);
        node_t* tmp2 = delete(heap);
        printf("-3 : ");
        bfs(heap);
        node_t* sumnode = merge(tmp1,tmp2);
        printf("left : %s , right : %s\n",sumnode->left->data,sumnode->right->data);
        insertnode(heap,sumnode);
    }
    printf("-5\n");
    bfs(heap);
    //printleaf(heap->array[1]);
    printf("%s",(((heap->array[1]->left)->right)->left)->data);
    return 0;
}