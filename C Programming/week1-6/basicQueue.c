#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

//typedef node_t queue_t;

node_t* enqueue(node_t* start, int val){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = val;
    node->next = NULL;
    node_t* last=NULL;
    if (start == NULL){
        start = node;
        last = start;
        return start;
    }else{
        last = start;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = node;
        return start;
    }
}

node_t* dequeue(node_t* start){
    node_t* tmp=NULL;
    if (start == NULL){
        printf("Queue is empty.\n");
    }else{
        tmp = start;
        start = start->next;
        printf("%d\n",tmp->data);
        free(tmp);
    }
    return start;
}

void show(node_t* start){
    int first = 1;
    if(start == NULL){
        printf("Queue is empty.\n");
    }else{
        while(start != NULL){
            if (first == 1){
                printf("%d",start->data);
                first = 0;
            }else{
                printf(" %d",start->data);
            }
            start = start->next;;
        }
    printf("\n");
    }
}

void empty(node_t* top){
    if (top==NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }
}

void size(node_t* start){
    int count=0;
    while(start != NULL){
        count++;
        start = start->next;
    }
    printf("%d\n",count);
}

int main(void) {
  node_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      /*case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;*/
    }
  }
  return 0;
}