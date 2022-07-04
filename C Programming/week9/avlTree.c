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
#include <math.h>

int balance(avl_t* t){
    int diff = 0;
    if (t->left != NULL && t->right != NULL){
        diff = t->left->height - t->right->height;
        diff = abs(diff);
    }else if(t->left == NULL && t->right != NULL){
        diff = t->right->height + 1;
        diff = abs(diff);
    }else if(t->left != NULL && t->right == NULL){
        diff = t->left->height + 1;
        diff = abs(diff);
    }else if(t->left == NULL && t->right == NULL){
        diff = 0;
    }
    if (diff <= 1){
        return 1;
    }else{
        return 0;
    }
}

int Check_case(avl_t* t){
    if (t->left != NULL && t->right != NULL){
        if (t->left->height > t->right->height){
            if ((t->left)->left->height > (t->left)->right->height){
                return 1;
            }else{
                return 3;
            }
        }else{
            if ((t->right)->right->height > (t->right)->left->height){
                return 2;
            }else{
                return 4;
            }
        }
    }
    if (t->left == NULL && t->right != NULL){
        return 2;
    }
    if (t->left != NULL && t->right == NULL){
        return 1;
    }
}

avl_t* right(avl_t* t){
    avl_t* a = t;
    t = t->left;
    a->left = t->right;
    t->right = a;
    t->height = t->left->height + 1;
    t->right->height = (t->right)->right->height + 1;
    return t;
}

avl_t* left(avl_t* t){
    printf("===1\n");
    avl_t* a = t;
    printf("===2\n");
    t = t->right;
    printf("===3\n");
    a->right = t->left;
    printf("===4\n");
    t->left = a;
    printf("===5\n");
    t->height = t->right->height + 1;
    printf("===6\n");
    t->left->height = (t->left)->left->height + 1;
    printf("===7\n");
    return t;
}

avl_t* insert(avl_t* t, int data){
    avl_t* node = (avl_t*)malloc(sizeof(avl_t));
    node->data = data;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    avl_t* pos = NULL;
    if (t==NULL){
        t = node;
        return t;
    }
    printf("---1\n");
    if (t->data > data){
        printf("---2\n");
        if(t->left == NULL){
            t->left = node;
            printf("---21\n");
            return t;
        }
        printf("---3\n");
        pos = insert(t->left,data);
    }else{
        printf("---4\n");
        if(t->right == NULL){
            t->right = node;
            printf("---41\n");
            return t;
        }
        printf("---5\n");
        pos = insert(t->right,data);
    }
    printf("---6\n");
    printf("pos data : %d\n",pos->data);
    if (pos->right != NULL && pos->left != NULL){
        pos->height = ((pos->left)->height > (pos->right)->height) ? (pos->left)->height + 1 : (pos->right)->height + 1;
    } else if(pos->right == NULL && pos->left != NULL){
        pos->height = pos->left->height + 1;
    } else if(pos->right != NULL && pos->left == NULL){
        pos->height = pos->right->height + 1;
    } else{
        pos->height = 0;
    }
    printf("---7\n");
    int check = balance(pos);
    printf("pos height : %d\n",pos->height);
    printf("---71\n");
    if (check == 0){
        printf("---72\n");
        int checkcase = Check_case(pos);
        printf("---73\n");
        if (checkcase == 1){
            printf("---74\n");
            pos = right(pos);
        } else if(checkcase == 2){
            printf("---75\n");
            pos = left(pos);
        } else if(checkcase == 3){
            printf("---76\n");
            avl_t* b = left(pos->left);
            pos->left = b;
            pos = right(pos);
        }else if(checkcase == 4){
            printf("---77\n");
            avl_t* b = right(pos->right);
            pos->right = b;
            pos = left(pos);
        }
    }
    printf("---8\n");
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
        //t = delete(t, data);
        break;
      case 3:
        print_tree(t);
        break;
    }
  }
  return 0;
}