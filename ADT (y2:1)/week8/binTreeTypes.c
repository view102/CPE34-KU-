#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#include <math.h>

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} tree_t;

//typedef node_t tree_t;
#endif

typedef struct nodeq{
    tree_t* data;
    struct nodeq* next;
} queue_t;

queue_t* enqueue(queue_t* start, tree_t* val){
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

tree_t* dequeue(queue_t** start){
    tree_t* tmp = (*start)->data;
    if ((*start)->next == NULL){
        *start = NULL;
    }else{
        *start = (*start)->next;
    }
    return tmp;
}

int height(tree_t* t){
    //printf("---a\n");
    if (t == NULL){
        //printf("---b\n");
        return -1;
    }
    //printf("---c\n");
    int hl = height(t->left);
    //printf("hl = %d\n",hl);
    int hr = height(t->right);
    //printf("hr = %d\n",hr);
    return (hl>hr) ? hl+1 : hr+1;
}

int is_full(tree_t* t){
    int result=1;
    if(t==NULL){
        return 0;
    }
    queue_t* q = NULL;
    q = enqueue(q,t);
    while(q!=NULL){
        tree_t* tmp = dequeue(&q);
        if(tmp->left == NULL && tmp->right != NULL){
            result = 0;
            break;
        }else if(tmp->left != NULL && tmp->right == NULL){
            result = 0;
            break;
        }
        if (tmp->right != NULL && tmp->left != NULL){
            q = enqueue(q,tmp->left);
            q = enqueue(q,tmp->right);
        }
    }
    return result;
}

int size(tree_t* t){
  if (t==NULL){
    return 0;
  }
  return size(t->left) + size(t->right) + 1;
}

int is_perfect(tree_t* t){
  return size(t) == pow(2,height(t)+1)-1;
}

int is_complete(tree_t* t){
    //printf("data : %d\n",t->data);
    if (height(t->left) - height(t->right) > 1){
        //printf(("case2\n"));
        return 0;
    }
    if (height(t->left) < height(t->right)){
        //printf("case3\n");
        return 0;
    }
    if (t == NULL || height(t) == 0){
        //printf("case4\n");
        return 1;
    }
    //printf("---1\n");
    if(height(t->left) - height(t->right) == 1){
        //printf("---3\n");
        if(height(t->left)!=0 && height(t->right)!=0){
            if ((is_complete(t->left) && is_perfect(t->right)) == 0){
                //printf("---4\n");
                return 0;
            }
        }
        //printf("---5\n");
    }else if (height(t->left) == height(t->right)){
        //printf("---6\n");
        if(height(t->left)!=0 && height(t->right)!=0){
            //printf("%d\n",is_perfect(t->left)&&is_complete(t->right));
            if ((is_perfect(t->left) && is_complete(t->right))==0){
                //printf("---7\n");
                return 0;
            }
        }
        //printf("---8\n");
    }
    //printf("---2\n");
    return 1;
}

int is_degenerate(tree_t* t){
    while(t!=NULL){
        if (t->left != NULL && t->right != NULL){
            return 0;
        }
        if (t->left != NULL && t->right == NULL){
            t=t->left;
        }else if(t->left == NULL && t->right != NULL){
            t=t->right;
        }else{
            return 1;
        }
    }
    return 1;
}

int is_skewed(tree_t* t){
    if (t->left != NULL && t->right != NULL){
        return 0;
    }
    int direct;
    if (t->left == NULL && t->right != NULL){
        direct = 2;
    }else if(t->left != NULL && t->right == NULL){
        direct = 1;
    }
    while(t!=NULL){
        if(direct == 1 && t->right != NULL){
            return 0;
        }
        if(direct == 2 && t->left != NULL){
            return 0;
        }
        if(direct==1){
            t=t->left;
        }else{
            t=t->right;
        }
    }
    return 1;
}

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}