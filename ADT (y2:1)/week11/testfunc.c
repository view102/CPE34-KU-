#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

unsigned int func(char str[], int hashkey, int len){
  if (len == 0){
    return (unsigned int)str[len];
  }
  return (hashkey * func(str,hashkey,len-1)) + str[len];
}

int main(){
    char text[] = "ab"; 
    printf("%u %d %lu",func(text, 7, strlen(text)-1),text[0],strlen(text));
}