#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} tree_t;

typedef node_t tree_t;
#endif

typedef struct nodeq {
    tree_t* pt;
    struct nodeq *next;
}queue_t;

queue_t* enqueue(queue_t* start, tree_t* pt){
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->pt = pt;
    q->next = NULL;
    if (start == NULL){
        start = q;
        return start;
    }
    while(start->next != NULL){
        start = start->next;
    }
    start->next = q;
    return start;
}

tree_t* dequeue(queue_t** start){
    tree_t* tmp = (*start)->pt;
    (*start) = (*start)->next;
    return tmp;
}

void inpreorder(tree_t* t){
    if(t!=NULL){
        printf("%d ",t->data);
        inpreorder(t->left);
        inpreorder(t->right);
    }
}

void print_preorder(tree_t* t){
    inpreorder(t);
    printf("\n");
}

void inpostorder(tree_t* t){
    if(t!=NULL){
        inpostorder(t->left);
        inpostorder(t->right);
        printf("%d ",t->data);
    }
}

void print_postorder(tree_t* t){
    inpostorder(t);
    printf("\n");
}

void ininorder(tree_t* t){
    if(t!=NULL){
        ininorder(t->left);
        printf("%d ",t->data);
        ininorder(t->right);
    }
}

void print_inorder(tree_t* t){
    ininorder(t);
    printf("\n");
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

  print_preorder(t);
  print_postorder(t);
  print_inorder(t);

  return 0;
}