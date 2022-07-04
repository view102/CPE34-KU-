#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

//typedef node_t stack_t;

node_t* push(node_t* top, int val){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = val;
    node->next = NULL;

    if(top == NULL){
        top = node;
        return top;
    }else{
        node->next = top;
        top = node;
        return top; 
    }
    return 0;
}

void top(node_t* top){
    if (top == NULL){
        printf("Stack is empty.\n");
    }else{
        printf("%d\n",top->data);
    }
}

node_t* pop(node_t* top){
    node_t* tmp=NULL;
    if(top==NULL){
        return top;
    }else{
        tmp = top;
        top = top->next;
        free(tmp);
        return top;
    }
    return top;
}

void empty(node_t* top){
    if (top==NULL){
        printf("Stack is empty.\n");
    }else{
        printf("Stack is not empty\n");
    }
}

void size(node_t* top){
    int count=0;
    while(top != NULL){
        count++;
        top = top->next;
    }
    printf("%d\n",count);
}

int main(void) {
  node_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;
      }
  }
  return 0;
}