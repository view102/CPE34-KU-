#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

heap_t* init_heap(int maxsize){
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->last_index = 1;
    heap->data = (int*)malloc(sizeof(int)*maxsize);
    return heap;
}

void sort_priority(heap_t* maxheap, int value, int index){
    int index_parent = index/2;
    int last = index;
    while(maxheap->data[index_parent] < value){
        if (index_parent == 0){
            break;
        }
        maxheap->data[last] = maxheap->data[index_parent];
        maxheap->data[index_parent] = value;
        last = index_parent;
        index_parent = index_parent/2;
    }
}

void insert(heap_t* maxheap, int value){
    int index_parent = maxheap->last_index/2;
    //printf("parent = %d\n",index_parent);
    if (maxheap->last_index == 1){
        maxheap->data[maxheap->last_index] = value;
    }else{
        maxheap->data[maxheap->last_index] = value;
        //check priority
        sort_priority(maxheap,value,maxheap->last_index);
    }
    maxheap->last_index++;
}

int max(heap_t* maxheap, int left, int right){
    if (maxheap->data[left] > maxheap->data[right]){
        return left;
    }else{
        return right;
    }
}

void delete_max(heap_t* maxheap){
    if(maxheap->last_index == 1){
        maxheap->data[maxheap->last_index] = 0;
    }else{
        int index = 1;
        maxheap->data[index] = maxheap->data[maxheap->last_index];
        maxheap->data[maxheap->last_index] = 0;
        maxheap->last_index--;
        int left = 2*index;
        int right = 2*index + 1;
        while(1){
            int next = max(maxheap,left,right);
            if (next > maxheap->last_index){
                break;
            }
            if (maxheap->data[index] < maxheap->data[next]){
                int tmp = maxheap->data[index];
                maxheap->data[index] = maxheap->data[next];
                maxheap->data[next] = tmp;
                index = next;
                left = 2*index;
                right = 2*index + 1;
            }else{
                break;
            }
        }
    }
}

void bfs(heap_t* maxheap){
    int i;
    for (i=1;i<maxheap->last_index;i++){
        printf("%d ",maxheap->data[i]);
    }
    printf("\n");
}

int find_max(heap_t* maxheap){
    if (maxheap->last_index == 1 || maxheap->data[1] == 0){
        return -1;
    }else{
        return maxheap->data[1];
    }
}

void update_key(heap_t* maxheap, int old, int new){
    int i = 1;
    while(maxheap->data[i] != old){
        i++;
    }
    //printf("%d\n",i);
    maxheap->data[i] = new;
    sort_priority(maxheap,new,i);
}


int main(void) {
  heap_t *max_heap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
      case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,
                   new_key);
        break;
      case 5:
        bfs(max_heap);
        break;
    }
  }
  return 0;
}