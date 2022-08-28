#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  int mem_addr;
} cell_t;

typedef struct hash {
  cell_t *table;
  int    cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int    memory_t;

memory_t *init_memory(int size) {
  memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
  int      i = 0;

  // Randomly assign integers to memory
  for (i=0; i<size; i++)
     memory[i] = rand();
  return memory;
}

int hashfunc(hash_t *hash, int address){
    return address%hash->cache_size;
}

hash_t* init_cache(int size){
    hash_t* tmp = (hash_t*)malloc(sizeof(hash_t));
    tmp->table = (cell_t*)malloc(sizeof(cell_t)*size);
    tmp->cache_size = size;
    int i;
    for (i=0;i<size;i++){
        tmp->table[i].data = -1;
    }
    return tmp;
}



void get_data(int address, memory_t *mem, hash_t *cache){
    unsigned int index = hashfunc(cache, address);
    if (cache->table[index].data == -1){
        printf("Load from memory\n");
        cache->table[index].data = mem[address];
        cache->table[index].mem_addr = address;
        printf("Data: %d\n",cache->table[index].data);
    } else {
        if (cache->table[index].data == mem[address]){
            printf("Address %d is loaded\n",address);
            printf("Data: %d\n",cache->table[index].data);
        }else if(cache->table[index].data != mem[address]){
            printf("Index: %d is used\n",index);
            printf("Load from memory\n");
            cache->table[index].data = mem[address];
            cache->table[index].mem_addr = address;
            printf("Data: %d\n",cache->table[index].data);
        }
    }
}

int main(void) {
  memory_t *memory = NULL;
  cache_t  *cache = NULL;
  int memory_size, cache_size;
  int i, n, addr;

  scanf("%d %d %d", &memory_size, &cache_size, &n);
  memory = init_memory(memory_size);
  cache = init_cache(cache_size);

  for (i=0; i<n; i++) {
    printf("Load address: ");
    scanf("%d", &addr);
    get_data(addr, memory, cache);
  }
  return 0;
}