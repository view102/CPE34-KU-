#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define Max_n 100

int traversemaze(char **mpp, char **spp, int x, int y, int n);

int main(){
    int n,i,j,x,y;
    char maze[Max_n][Max_n];
    char sol[Max_n][Max_n];
    char **mp,**sp;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        getchar();
        scanf("%[^\n]s",maze[i]);
        strcpy(sol[i],maze[i]);
    }
    mp = (char **)malloc(sizeof(char *)*n);
    sp = (char **)malloc(sizeof(char *)*n);
    for (i=0;i<n;i++){
        mp[i] = maze[i];
        sp[i] = sol[i];
        }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (mp[i][j]=='S'){
                if (i==0){
                    x=i+1;
                    y=j;
                }else if(j==0){
                    y=j+1;
                    x=i;
                }else if(i==n-1){
                    x=i-1;
                    y=j;
                }else if(j==n-1){
                    x=i;
                    y=j-1;
                }
            }
        }
    }
    //printf("%d",x);
    mp[x][y]=' ';
    sp[x][y]=' ';
    traversemaze(mp,sp,x,y,n);
    for(i=0;i<n;i++){
        printf("%s\n",sp[i]);
    }
    return 0;
}

int traversemaze(char **mpp, char **spp, int x, int y, int n){
    if ((x>0 && y>0 && x<n-1 && y<n-1) && (mpp[x][y+1]=='G' || mpp[x+1][y]=='G' || mpp[x][y-1]=='G' || mpp[x-1][y]=='G')){
        spp[x][y]='.';
        return 1;
    }else{
        if ((x>0 && y>0 && x<n-1 && y<n-1) && (spp[x][y]==' ' && mpp[x][y]==' ')){
            spp[x][y]='.';
            if (traversemaze(mpp,spp,x-1,y,n)){
                return 1;
            }
            if (traversemaze(mpp,spp,x,y+1,n)){
                return 1;
            }
            if (traversemaze(mpp,spp,x+1,y,n)){
                return 1;
            }
            if (traversemaze(mpp,spp,x,y-1,n)){
                return 1;
            }
            spp[x][y]=' ';
            return 0;
        }
        return 0;
    }
}