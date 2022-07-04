#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
  int    data;
  int    height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

int max(int a,int b){
    return (a>b) ? a : b;
}

int height(avl_t* t){
  if (t==NULL){
    return -1;
  }
  return t->height;
}

avl_t* createNode(int data){
  avl_t* node = (avl_t*)malloc(sizeof(avl_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return node;
}

avl_t* right(avl_t* t){
  avl_t* b = t->left;
  avl_t* i = b->right;
  b->right = t;
  t->left = i;

  t->height = max(height(t->left),height(t->right)) + 1;
  b->height = max(height(b->left),height(b->right)) + 1;

  return b;
}

avl_t* left(avl_t* t){
  avl_t* b = t->right;
  avl_t* i = b->left;
  b->left = t;
  t->right = i;

  t->height = max(height(t->left),height(t->right)) + 1;
  b->height = max(height(b->left),height(b->right)) + 1;

  return b;
}

int balance(avl_t* t){
  if (t==NULL){
    return 0;
  }
  return height(t->left)-height(t->right);
}

avl_t* insert(avl_t* t, int data){
  if (t==NULL){
    return createNode(data);
  }
  if (t->data > data){
    t->left = insert(t->left,data);
  } else{
    t->right = insert(t->right,data);
  }
  t->height = max(height(t->right),height(t->left)) + 1;
  int checkbalance = balance(t);
  if (checkbalance > 1 && data < (t->left->data)){
    return right(t);
  }
  if (checkbalance < -1 && data > (t->right->data)){
    return left(t);
  }
  if (checkbalance > 1 && data > (t->left->data)){
    t->left = left(t->left);
    return right(t);
  }
  if (checkbalance < -1 && data < (t->right->data)){
    t->right = right(t->right);
    return left(t);
  }
  return t;
}

avl_t* find_min(avl_t* t){
    avl_t* min = t;
    while (min && min->left != NULL){
      min = min->left;
    }
    return min;
}

avl_t* delete(avl_t* t, int data){
  if (t==NULL){
    return t;
  }
  if (t->data > data){
    t->left = delete(t->left,data);
  } else if(t->data < data){
    t->right = delete(t->right,data);
  } else {
    if(t->left == NULL || t->right == NULL){
      avl_t* tmp = t->left ? t->left : t->right;
      if(tmp == NULL){
        tmp = t;
        t = NULL;
      }else{
        *t = *tmp;
      }
      free(tmp);
    }
    else{
      avl_t* minnode = find_min(t->right);
      t->data = minnode->data;
      t->right = delete(t->right,minnode->data);
    }
  }
  if (t==NULL){
    return t;
  }
  t->height = max(height(t->right),height(t->left)) + 1;
  int checkbalance = balance(t);
  if (checkbalance > 1 && balance(t->left) >= 0){
    return right(t);
  }
  if (checkbalance < -1 && balance(t->right) <= 0){
    return left(t);
  }
  if (checkbalance > 1 && balance(t->left) < 0){
    t->left = left(t->left);
    return right(t);
  }
  if (checkbalance < -1 && balance(t->right) > 0){
    t->right = right(t->right);
    return left(t);   
  }
  return t;
}

int main(void) {
  avl_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        print_tree(t);
        break;
    }
  }
  return 0;
}