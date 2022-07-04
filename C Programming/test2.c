#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

heap_t* init_heap(int maxsize){
    heap_t heap = {NULL,-1};
    heap_t* heapp = &heap;
    heapp->data = (int*)malloc(sizeof(int)*maxsize);
    return heapp;
}

void insert(heap_t* maxheap, int value){
    int index_parent = maxheap->last_index/2;
    printf("---1\n");
    if (maxheap->last_index == -1){
        printf("---2\n");
        maxheap->data[(maxheap->last_index)+1] = value;
    }else{
        printf("---3\n");
        maxheap->data[maxheap->last_index] = value;
        //check priority
        printf("---4\n");
        int last = maxheap->last_index;
        printf("---5\n");
        while(maxheap->data[index_parent] < value){
            printf("---6\n");
            maxheap->data[last] = maxheap->data[index_parent];
            printf("---7\n");
            maxheap->data[index_parent] = value;
            printf("---8\n");
            index_parent = index_parent/2;
        }
    }
    printf("---9\n");
    maxheap->last_index++;
}



int main(void) {
  heap_t *maxheap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key, value;

  scanf("%d %d", &m, &value);
  maxheap = init_heap(m);
  int index_parent = maxheap->last_index/2;
  printf("%d\n",maxheap->last_index);
  printf("%d\n",maxheap->last_index);
  printf("%d\n",maxheap->last_index);
  if ((maxheap->last_index) == 0){
    printf("%d\n",maxheap->last_index);
    printf("---2\n");
    maxheap->data[maxheap->last_index] = 1;
  }else{
    printf("---3\n");
    printf("%d\n",maxheap->last_index);
    maxheap->data[maxheap->last_index] = value;
    //check priority
    printf("---4\n");
    int last = maxheap->last_index;
    printf("---5\n");
    while(maxheap->data[index_parent] < value){
        printf("---6\n");
        maxheap->data[last] = maxheap->data[index_parent];
        printf("---7\n");
        maxheap->data[index_parent] = value;
        printf("---8\n");
        index_parent = index_parent/2;
    }
  }
  printf("---9\n");
  maxheap->last_index++;
  return 0;
}