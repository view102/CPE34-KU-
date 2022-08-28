#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef struct item {
  char   *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
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
  hash->table = (item_t**)malloc(sizeof(item_t*)*size);
  int i;
  for(i=0;i<size;i++){
    hash->table[i] = NULL;
  }
  return hash;
}

item_t* newitem(char *str){
  item_t* tmp = (item_t*)malloc(sizeof(item_t));
  tmp->text = (char*)malloc(sizeof(char)*TEXTSIZE);
  strcpy(tmp->text,str);
  tmp->next = NULL;
  return tmp;
}

void insert(hash_t* hash, char *str){
  int index = hashfunc(str,hash->hash_key,hash->size);
  if (hash->table[index] == NULL){
    hash->table[index] = newitem(str);
  }else{
    item_t* tmp = hash->table[index];
    item_t* tmp2 = newitem(str);
    hash->table[index] = tmp2;
    hash->table[index]->next = tmp;
  }
}

int search(hash_t* hash, char *str){
  int index = hashfunc(str,hash->hash_key,hash->size);
  item_t* tmp = hash->table[index];
  while(tmp!=NULL){
    if(strcmp(tmp->text,str) == 0){
      return index;
    }
    tmp = tmp->next;
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