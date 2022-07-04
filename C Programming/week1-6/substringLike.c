#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void substring(char *mpp, char *ppp, char *sstr, int m, int p, int n, int *c);

int main(){
    int m,p,n,count=0;
    char *mp=NULL,*pp=NULL,*substr=NULL,*text=NULL;
    scanf("%d %d %d",&m,&p,&n);
    mp = (char*)malloc(sizeof(char)*m);
    pp = (char*)malloc(sizeof(char)*p);
    substr = (char*)malloc(sizeof(char)*(m*2));
    scanf("%s",mp);
    scanf("%s",pp);
    //printf("%s %s\n",mp,pp);
    substring(mp,pp,substr,m,p,n,&count);
    text = (char*)malloc(sizeof(char)*count);
    //int s=sizeof(*text)/sizeof(text[0]);
    strncat(text,substr,count);
    //printf("%d\n",count);
    printf("%s\n",text);
    return 0;
}

void substring(char *mpp, char *ppp, char *sstr, int m, int p, int n, int *c){
    char *tmp;
    int i,error=0;
    //printf("{%s}\n",sstr);
    //printf("%d %d\n",start,m);
    if (m<p){
        tmp = (char *)malloc(sizeof(char)*m);
        for (i=0;i<m;i++){
            char text=mpp[i];
            strcpy(tmp+i,&text);
            *c+=1;
        }
        strcat(sstr,tmp);
    }else{
        tmp = (char *)malloc(sizeof(char)*(p+2));
        for (i=0;i<p;i++){
            if (mpp[i]==ppp[i]){
                char text=mpp[i];
                strcat(tmp,&text);
            }else{
                strcat(tmp,"?");
                error+=1;
            }
        }
        //printf("0.%s\n",sstr);
        if (error>n){
            //char text=mpp[0];
            strncat(sstr,mpp,1);
            //printf("1.%s\n",sstr);
            *c+=1;
            substring(mpp+1,ppp,sstr,m-1,p,n,c);

        }else{
            //printf("%s\n",tmp);
            strcat(sstr,"[");
            strcat(sstr,tmp);
            strcat(sstr,"]");
            //printf("2.%s\n",sstr);
            *c+=(p+2);
            substring(mpp+p,ppp,sstr,m-p,p,n,c);
        }
    }
}
