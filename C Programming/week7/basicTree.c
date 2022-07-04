#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *sibling;
    struct node *firstchild;
}tree_t;

typedef struct nodeq{
    int data;
    struct nodeq *next;
}queue_t;

queue_t* enqueue(queue_t* start, int val){
    queue_t* nodeq = (queue_t*)malloc(sizeof(queue_t));
    nodeq->data = val;
    nodeq->next = NULL;
    if (start == NULL){
        start = nodeq;
        return start;
    }
    queue_t* tmp = start;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = nodeq;
    return start;
}

int dequeue(queue_t** start){
    int tmp = (*start)->data;
    if ((*start)->next == NULL){
        *start = NULL;
    }else{
        *start = (*start)->next;
    }
    return tmp;
}

tree_t* searchpos(tree_t* t, int val){
    tree_t* pos = NULL;
    if (t == NULL || t->value == val){
        return t;
    }
    pos = searchpos(t->firstchild,val);
    if (pos != NULL){
        return pos;
    }else{
        return searchpos(t->sibling,val);
    }
}

tree_t* searchposbefore(tree_t* t, tree_t* before, int val){
    tree_t* pos = NULL;
    if (t == NULL){
        return t;
    }
    if (t->value == val){
        return before;
    }
    pos = searchposbefore(t->firstchild,t,val);
    if (pos != NULL){
        return pos;
    }else{
        return searchposbefore(t->sibling,t,val);
    }
}

tree_t* attach(tree_t* t, int parent, int val){
    tree_t* node = (tree_t*)malloc(sizeof(tree_t));
    node->value = val;
    node->sibling = NULL;
    node->firstchild = NULL;
    if (parent == -1){
        return node;
    }
    tree_t* nodeparent = searchpos(t,parent);
    //printf("%d\n",nodeparent->value);
    tree_t* nodechild = nodeparent->firstchild;
    if(nodechild == NULL){
        nodeparent->firstchild = node;
        return t;
    }
    while(nodechild->sibling != NULL){
        nodechild = nodechild->sibling;
    }
    nodechild->sibling = node;
    return t;
}

tree_t* detach(tree_t* t, int node){
    tree_t* detachpos = searchposbefore(t,t,node);
    //printf("before : %d\n",detachpos->value);
    if (detachpos->firstchild != NULL && (detachpos->firstchild)->value == node){
        //printf("before is parent\n");
        //tree_t* tmp = detachpos->firstchild;
        detachpos->firstchild = (detachpos->firstchild)->sibling;
    }
    if(detachpos->sibling != NULL && (detachpos->sibling)->value == node){
        //printf("before is sibling\n");
        detachpos->sibling = (detachpos->sibling)->sibling;
    }
    return t;
}

int search(tree_t* t, int val){
    int pos;
    if (t == NULL){
        return 0;
    }
    if (t->value == val){
        return 1;
    }
    pos = search(t->firstchild,val);
    if (pos != 0){
        return 1;
    }else{
        return search(t->sibling,val);
    }
    return 0;
}

int degree(tree_t* t, int node){
    tree_t* pos = searchpos(t,node);
    int count=0;
    if (pos->firstchild == NULL){
        return 0;
    }else{
        pos = pos->firstchild;
        while(pos != NULL){
            count++;
            pos = pos->sibling;
        }
    }
    return count;
}

int is_root(tree_t* t, int node){
    if (node != t->value){
        return 0;
    }else{
        return 1;
    }
}

int is_leaf(tree_t* t, int node){
    tree_t* pos = searchpos(t,node);
    if (pos->firstchild == NULL){
        return 1;
    }else{
        return 0;
    }
}

void siblings(tree_t* t, int node){
    queue_t* start = NULL;
    //printf("---1\n");
    int found=0;
    //printf("---2\n");
    start = enqueue(start, t->value);
    //printf("---3\n");
    while(1){
        //printf("---4\n");
        if (node == t->value){
            break;
        }
        //printf("---5\n");
        int tmp = dequeue(&start);
        //printf("---6 tmp : %d\n",tmp);
        tree_t* pos = searchpos(t,tmp);
        //printf("---7 pos->value : %d\n",pos->value);
        tree_t* parent = pos;
        //printf("---8\n");
        pos = pos->firstchild;
        //printf("---9\n");
        while(pos != NULL){
            //printf("---10\n");
            //printf("pos value is %d\n",pos->value);
            if(pos->value == node){
                //printf("---11 found\n");
                found = 1;
            }
            //printf("---12\n");
            start = enqueue(start, pos->value);
            //printf("---13\n");
            pos = pos->sibling;
            //printf("---14\n");
        }
        if (found == 1){
            //printf("---15\n");
            parent = parent->firstchild;
            //printf("---16\n");
            while(parent != NULL){
                if (parent->value != node){
                    //printf("---17\n");
                    printf("%d ",parent->value);
                }
                //printf("---18\n");
                parent = parent->sibling;
            }
            //printf("---19\n");
            break;
        }
    }
    //printf("---end\n");
    printf("\n");
}

int depth(tree_t* t, int node){
    int count=0, found=0;
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    q2 = enqueue(q2,t->value);
    while(1){
        if (q1 == NULL){
            while(q2 != NULL){
                int tmp = dequeue(&q2);
                if (tmp == node){
                    found = 1;
                }
                tree_t* pos = searchpos(t,tmp);
                pos = pos->firstchild;
                while(pos != NULL){
                    q1 = enqueue(q1,pos->value);
                    pos = pos->sibling;
                }
            }
        } else if (q2 == NULL){
            while(q1 != NULL){
                int tmp = dequeue(&q1);
                if (tmp == node){
                    found = 1;
                }
                tree_t* pos = searchpos(t,tmp);
                pos = pos->firstchild;
                while(pos != NULL){
                    q2 = enqueue(q2,pos->value);
                    pos = pos->sibling;
                }
            }
        }
        if (found == 1){
            break;
        }
        count++;
    }
    return count;
}

void print_path(tree_t* t, int start, int end){
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    tree_t* posend = searchpos(t,end);
    q1 = enqueue(q1,posend->value);
    if(start == end){
        printf("%d\n",start);
    }else{
        while(1){
            tree_t* before = searchposbefore(t,t,posend->value);
            if (before->firstchild != NULL && (before->firstchild)->value == posend->value){
                while (q1 != NULL){
                    int tmp = dequeue(&q1);
                    q2 = enqueue(q2,tmp);
                }
                q1 = enqueue(q1,before->value);
                while (q2 != NULL){
                    int tmp2 = dequeue(&q2);
                    q1 = enqueue(q1,tmp2);
                }
            }
            posend = before;
            if (before->value == start){
                break;
            }
        }
        while(q1!=NULL){
            printf("%d ",dequeue(&q1));
        }
        printf("\n");
    }
}

int path_length(tree_t* t, int start, int end){
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    tree_t* posend = searchpos(t,end);
    int count = 0;
    q1 = enqueue(q1,posend->value);
    if(start == end){
        return count+1;
    }
    while(1){
        tree_t* before = searchposbefore(t,t,posend->value);
        if (before->firstchild != NULL && (before->firstchild)->value == posend->value){
            while (q1 != NULL){
                int tmp = dequeue(&q1);
                q2 = enqueue(q2,tmp);
            }
            q1 = enqueue(q1,before->value);
            while (q2 != NULL){
                int tmp2 = dequeue(&q2);
                q1 = enqueue(q1,tmp2);
            }
            count++;
        }
        posend = before;
        if (before->value == start){
            break;
        }
    }
    return count+1;
}

void ancestor(tree_t* t, int node){
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    tree_t* posend = searchpos(t,node);
    q1 = enqueue(q1,posend->value);
    while(1){
        tree_t* before = searchposbefore(t,t,posend->value);
        if (before->firstchild != NULL && (before->firstchild)->value == posend->value){
            while (q1 != NULL){
                int tmp = dequeue(&q1);
                q2 = enqueue(q2,tmp);
            }
            q1 = enqueue(q1,before->value);
            while (q2 != NULL){
                int tmp2 = dequeue(&q2);
                q1 = enqueue(q1,tmp2);
            }
        }
        posend = before;
        if (before->value == t->value){
            break;
        }
    }
    while(q1!=NULL){
        printf("%d ",dequeue(&q1));
    }
    printf("\n");
}

void descendant(tree_t* t, int node){
    queue_t* q = NULL;
    tree_t* pos = searchpos(t,node);
    q = enqueue(q,pos->value);
    while(q != NULL){
        int tmp = dequeue(&q);
        printf("%d ",tmp);
        pos = searchpos(t,tmp);
        pos = pos->firstchild;
        while(pos != NULL){
            q = enqueue(q,pos->value);
            pos = pos->sibling;
        }
    }
    printf("\n");
}

void bfs(tree_t* t){
    descendant(t,1);
}

void dfs(tree_t* t){
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    q1 = enqueue(q1,t->value);
    while(q1 != NULL){
        int tmp = dequeue(&q1);
        while(q1 != NULL){
            q2 = enqueue(q2,dequeue(&q1));
        }
        printf("%d ",tmp);
        tree_t* pos = searchpos(t,tmp);
        pos = pos->firstchild;
        while(pos != NULL){
            q1 = enqueue(q1,pos->value);
            pos = pos->sibling;
        }
        while(q2 != NULL){
            q1 = enqueue(q1,dequeue(&q2));
        }
    }
    printf("\n");
}

void print_tree(tree_t* t){
    queue_t* q1 = NULL;
    queue_t* q2 = NULL;
    int i;
    q1 = enqueue(q1,t->value);
    while(q1 != NULL){
        int tmp = dequeue(&q1);
        while(q1 != NULL){
            q2 = enqueue(q2,dequeue(&q1));
        }
        int d = depth(t,tmp);
        for(i=0;i<4*d;i++){
            printf(" ");
        }
        printf("%d\n",tmp);
        tree_t* pos = searchpos(t,tmp);
        pos = pos->firstchild;
        while(pos != NULL){
            q1 = enqueue(q1,pos->value);
            pos = pos->sibling;
        }
        while(q2 != NULL){
            q1 = enqueue(q1,dequeue(&q2));
        }
    }
}

int main(void) {
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n", path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}