#include<stdio.h>
#include<stdlib.h>

typedef struct player {
    int limit;
    int count;
    int number;
    struct player* next;
}player_t;

player_t* append(player_t** start, player_t** last, player_t** ptmp, long n, long limit, int link, int* nplayer){
    player_t* player=(player_t*)malloc(sizeof(player_t));
    player->limit = limit;
    player->count = 0;
    player->number = (*nplayer)+1;
    player->next = NULL;
    if (*start == NULL){
        *start = player;
        *last = *start;
        *ptmp=NULL;
        (*nplayer)++;
        //printf("-%d\n",*nplayer);
        return *start;
    }
    if (link==1){
        (*last)->next = player;
        *last = player;
        *ptmp = *last;
        player->next = *start;
        (*nplayer)++;
        //printf("-%d\n",*nplayer);
        return *start;
    }
    (*last)->next = player;
    *ptmp = *last;
    *last = player;
    (*nplayer)++;
    //printf("-%d\n",*nplayer);
    return *start;
}

void show(player_t* start, int* nplayer){
    int i;
    for (i=0;i< (*nplayer);i++){
        printf("%d ",start->number);
        start = start->next;
    }
} 

player_t* delete(player_t** start, player_t** ptmp, int* nplayer){
    (*ptmp)->next = (*start)->next;
    *start = (*start)->next;
    (*nplayer)--;
    //printf("-%d\n",*nplayer);
    return *start;
}

int check(int count, long k){
    int i;
    while(count!=0){
        i = count%10;
        if (i == k){
            return 1;
        }
        count = count/10;
    }
    return 0;
}

int main(){
    int nplayer=0,i,count=1;
    player_t* startNode;
    player_t* tmp;
    player_t* lastNode;
    long n,k,limit;
    startNode=NULL;
    tmp=NULL;
    lastNode=NULL;
    scanf("%ld %ld",&n,&k);
    for(i=0;i<n;i++){
        scanf(" %ld",&limit);
        if (i==n-1){
            startNode = append(&startNode,&lastNode,&tmp,n,limit,1,&nplayer);
            break;
        }
        startNode = append(&startNode,&lastNode,&tmp,n,limit,0,&nplayer);
    }
    //show(startNode,&nplayer);
    while(1){
        if (nplayer == 1){
            break;
        }
        int checknum = check(count,k); 
        if (count%k==0 || checknum == 1){
            (startNode->count)++;
        }
        if ((startNode)->count > (startNode)->limit){
            startNode = delete(&startNode,&tmp,&nplayer);
            count++;
            continue;
        }else{
            tmp = startNode;
            startNode = startNode->next;
            count++;
        }
    }
    show(startNode,&nplayer);
}