#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} bst_t;

//typedef node_t bst_t;

bst_t* insert(bst_t* t, int data){
    bst_t* node = (bst_t*)malloc(sizeof(bst_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if(t == NULL){
        t=node;
        return t;
    }
    bst_t* tmp = t;
    while(1){
        if (data < tmp->data){
            if(tmp->left == NULL){
                tmp->left = node;
                break;
            }
            tmp = tmp->left;
        }else if(data > tmp->data){
            if(tmp->right == NULL){
                tmp->right = node;
                break;
            }
            tmp = tmp->right;
        }
    }
    return t;
}

int find_min(bst_t* t){
    if (t->left == NULL){
        return t->data;
    }
    return find_min(t->left);
}

int find_max(bst_t* t){
    if (t->right == NULL){
        return t->data;
    }
    return find_max(t->right);
}

bst_t* findpos(bst_t* t, int data){
    bst_t* pos = NULL;
    if (t == NULL || t->data == data){
        return t;
    }
    if (data > t->data){
        return findpos(t->right,data);
    }else{
        return findpos(t->left,data);
    }
}

bst_t* findbefore(bst_t* t, int data){
    if(t->left == NULL && t->right == NULL){
        return NULL;
    }
    if (t->left != NULL && (t->left)->data == data){
        return t;
    }else if(t->right != NULL && (t->right)->data == data){
        return t;
    }
    if (t->data > data){
        return findbefore(t->left,data);
    }else{
        return findbefore(t->right,data);
    }
}

bst_t* delete(bst_t* t, int data){
    bst_t* pos = findpos(t,data);
    if (t == NULL){
        return t;
    }
    if (pos->left != NULL && pos->right == NULL){
        pos->data = (pos->left)->data;
        pos->right = (pos->left)->right;
        pos->left = (pos->left)->left;
        return t;
    }
    if (pos->left == NULL && pos->right != NULL){
        pos->data = (pos->right)->data;
        pos->left = (pos->right)->left;
        pos->right = (pos->right)->right;
        return t;
    }
    if (pos->left == NULL && pos->right == NULL){
        bst_t* before = findbefore(t,data);
        if (before->left != NULL && (before->left)->data == data){
            before->left = NULL;
            return t;
        }
        if (before->right != NULL && (before->right)->data == data){
            before->right = NULL;
            return t;
        }
    }
    if (pos->left != NULL && pos->right != NULL){
        int min = find_min(pos->right);
        t = delete(t,min);
        pos->data = min;
        return t;
    }
    return t;
}

int find(bst_t* t, int data){
    if(t == NULL){
        return 0;
    }
    if (t->data == data){
        return 1;
    }
    if (t->data > data){
        return find(t->left,data);
    }else{
        return find(t->right,data);
    }
}

int main(void) {
  bst_t *t = NULL;
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
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}