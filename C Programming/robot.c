#include<stdio.h>
#include<math.h>

char compass(char from, char move);

int main(){
    char direction = 'E';
    int x=0,y=0;
    int n;
    scanf("%d",&n);
    char command[n];
    scanf("%s",command);
    int i;
    for (i=0;i<n;i++){
        if (command[i]=='R' || command[i]=='L'){
            direction = compass(direction,command[i]);
        }
        if (command[i]=='F'){
            if (direction=='N'){
                y++;
            } else if (direction=='E'){
                x++;
            } else if (direction=='S'){
                y--;
            } else {
                x--;
            }
        }
    }
    double a=pow(x,2), b=pow(y,2);
    double distance = sqrt(a+b);
    printf("%.4lf",distance);
    //printf("%d %c",n,command[0]);
    //printf("%c",compass(direction,'R'));
    //printf("%c",direction);
    return 0;
}

char compass(char from, char move){
    if (from=='N'){
        if (move=='R'){
            return 'E';
        }
        if (move=='L'){
            return 'W';
        }
    }else if (from=='W'){
        if (move=='R'){
            return 'N';
        }
        if (move=='L'){
            return 'S';
        }
    }else if (from=='S'){
        if (move=='R'){
            return 'W';
        }
        if (move=='L'){
            return 'E';
        }
    }else if (from=='E'){
        if (move=='R'){
            return 'S';
        }
        if (move=='L'){
            return 'N';
        }
    }else{
        return from;
    }
    return from;
}