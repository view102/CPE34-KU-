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

bst_t* findpos(bst_t* t, int data){
    bst_t* pos = t;
    //printf("findpos pos : %d\n",pos->data);
    //printf("--3\n");
    if (pos->data == data){
        //printf("--4\n");
        return pos;
    }
    //printf("--5\n");
    if (pos->data > data){
        //printf("--6\n");
        return findpos(pos->left,data);
    }else{
        //printf("--7\n");
        return findpos(pos->right,data);
    }
}

bst_t* findbefore(bst_t* t, int data){
    //printf("----1\n");
    if(t->left == NULL && t->right == NULL){
        //printf("----2\n");
        return NULL;
    }
    //printf("----3\n");
    if (t->left != NULL && (t->left)->data == data){
        //printf("----4\n");
        return t;
    }else if(t->right != NULL && (t->right)->data == data){
        //printf("----5\n");
        return t;
    }
    //printf("----6\n");
    if (t->data > data){
        //printf("----7\n");
        return findbefore(t->left,data);
    }else{
        //printf("----8\n");
        return findbefore(t->right,data);
    }
    //printf("----9\n");
}

int find_min(bst_t* t){
    while(1){
        if (t->left == NULL){
            return t->data;
        }
        t = t->left;
    }
}

int find_max(bst_t* t){
    while(1){
        if (t->right == NULL){
            return t->data;
        }
        t = t->right;
    }
}

bst_t* delete(bst_t* t, int data){
    bst_t* pos = findpos(t,data);
    //printf("pos->data : %d\n",pos->data);
    if (pos->left == NULL && pos->right == NULL){
        //printf("---1\n");
        bst_t* before = findbefore(t,data);
        //printf("before : %d\n",before->data);
        if (before->data > data){
            //printf("---11\n");
            before->left = NULL;
        }else{
            //printf("---12\n");
            //printf("before data : %d\n",before->data);
            before->right = NULL;
        }
    }else if(pos->left != NULL && pos->right != NULL){
        //printf("---2\n");
        int min = find_min(pos->right);
        //printf("min : %d\n",min);
        bst_t* posmin = findpos(t,min);
        if (posmin->right!=NULL){
            bst_t* beforemin = findbefore(t,min);
            beforemin->right = posmin->right;
        }else{
            bst_t* beforemin = findbefore(t,min);
            beforemin->left = NULL;
        }
        pos->data = min;
    }else{
        //printf("---3\n");
        if (pos->right != NULL){
            //printf("---31\n");
            pos->data = (pos->right)->data;
            pos->right = NULL;
        }else{
            //printf("---32\n");
            pos->data = (pos->left)->data;
            pos->left = NULL;
        }
    }
    //printf("---4\n");
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