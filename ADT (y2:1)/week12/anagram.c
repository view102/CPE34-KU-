#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct str{
    char *sort;
    char *str;
}str_t;

char* lowercasestr(char str[50]){
    int len = strlen(str);
    int i;
    char* strp = NULL;
    strp = (char*)malloc(sizeof(char)*50);
    for(i=0;i<len;i++){
        if(str[i]>=65 && str[i]<=90){
            strp[i] = str[i]+32;
        }else{
            strp[i] = str[i];
        }
    }
    return strp;
}

void insertion_sort(char* list, int n, int index){
    int i = index;
    if(index < n){
        while(i > 0){
            if (list[i] < list[i-1]){
                int tmp = list[i];
                list[i] = list[i-1];
                list[i-1] = tmp;
            }
            i--;
        }
        insertion_sort(list,n,index+1);
    }
}

int main(){
    str_t *str_list = NULL;
    int m,n,i;
    char tmp[50];
    scanf("%d %d",&m,&n);
    str_list = (str_t*)malloc(sizeof(str_t)*m);
    for(i=0;i<m;i++){
        str_list[i].str = (char*)malloc(sizeof(char)*50);
        str_list[i].sort = (char*)malloc(sizeof(char)*50);
    }
    for(i=0;i<m;i++){
        scanf("%s",tmp);
        char* tmp2 = lowercasestr(tmp);
        int len = strlen(tmp2);
        int j;
        strcpy(str_list[i].str,tmp);
        strcpy(str_list[i].sort,tmp2);
        insertion_sort(str_list[i].sort, len, 1);
    }
    for(i=0;i<n;i++){
        int tmp_asc = 0;
        int error = 0;
        scanf("%s",tmp);
        char* tmp2 = lowercasestr(tmp);
        int len1 = strlen(tmp2);
        int j;
        insertion_sort(tmp2,len1,1);
        for(j=0;j<m;j++){
            int k;
            //printf("Check// %s , tmp2 : %s\n",str_list[j].sort,tmp2);
            if(strlen(str_list[j].sort)==len1){
                for(k=0;k<len1;k++){
                    if((int)str_list[j].sort[k] != (int)tmp2[k]){
                        error = 1;
                        break;
                    }
                }
                if (error == 0){
                    printf("%s ",str_list[j].str);
                }else{
                    error = 0;
                }
            }
        }
        printf("\n");
    }
}