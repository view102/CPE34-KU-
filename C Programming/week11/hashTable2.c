#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

unsigned int func(char *str, int hashkey, int len){
  if (len == 0){
    return str[len];
  }
  return (hashkey * func(str,hashkey,len-1)) + str[len];
}

unsigned int hashfunc(char *str, int hashkey, int size){
  return func(str,hashkey,strlen(str)-1)%size;
}

hash_t* init_hashtable(int size, int hashkey){
  hash_t* hash = (hash_t*)malloc(sizeof(hash_t));
  hash->size = size;
  hash->hash_key = hashkey;
  hash->table = (item_t*)malloc(sizeof(item_t)*size);
  int i;
  for(i=0;i<size;i++){
    hash->table[i] = NULL;
  }
  return hash;
}

item_t newnode(char *str){
    item_t tmp = (item_t)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp,str);
    return tmp;
}

void insert(hash_t* hash, char *str){
    int index = hashfunc(str,hash->hash_key,hash->size);
    int firstindex = index;
    if(hash->table[index] == NULL){
        hash->table[index] = newnode(str);
    }else{
        int i=0;
        while(1){
            index = (firstindex + (i + i*i)/2) % hash->size;
            if(hash->table[index] == NULL){
                hash->table[index] = newnode(str);
                break;
            }
            i++;
        }
    }
}

int search(hash_t *hash, char *str){
    int index = hashfunc(str,hash->hash_key,hash->size);
    int i=0;
    int firstindex = index;
    while(1){
        index = (firstindex + (i + i*i)/2) % hash->size;
        if(hash->table[index] == NULL){
            break;
        }
        if(strcmp(hash->table[index],str) == 0){
            return index;
        }
        i++;
    }
    return -1;
}

int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}