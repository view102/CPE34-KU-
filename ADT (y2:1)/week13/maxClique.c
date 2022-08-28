#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

int max(int a, int b){
    return a>b ? a : b;
}

int isclique(int graph[MAXSIZE][MAXSIZE], int store[MAXSIZE], int x){
    int i,j;
    for (i=1;i<x;i++){
        for(j=i+1;j<x;j++){
            if(graph[store[i]][store[j]] == 0){
                return 0;
            }
        }
    }
    return 1;
}

int findmaxcliques(int graph[MAXSIZE][MAXSIZE], int store[MAXSIZE] ,int s, int f, int n){
    int max_c = 0;
    int i;
    for(i = s + 1;i<=n;i++){
        store[f] = i;
        if(isclique(graph,store,f+1)){
            max_c = max(max_c,f);
            max_c = max(max_c,findmaxcliques(graph,store,i,f+1,n));
        }
    }
    return max_c;
}

int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    int graph[MAXSIZE][MAXSIZE];
    int store[MAXSIZE];
    int* edge = (int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        int x,y;
        x = u+1;
        y = v+1;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int Maxc = findmaxcliques(graph,store,0,1,n);
    printf("%d",Maxc);
    return 0;
}