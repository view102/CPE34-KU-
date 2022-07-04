#include<stdio.h>

int n;

int main(){
    int i;
    int count = 0;
    scanf("%d",&n);

    int player[n];
    int return_gift[n];
    int holding[n];
    int hold[n];
    for(i = 0; i < n; i++){
        scanf("%d",&player[i]);
        return_gift[i] = 0;
        holding[i] = i + 1;
        hold[i] = i + 1;
    }

    while(1){
        for(i = 0; i < n; i++){
            hold[player[i]-1] = holding[i];
            if (player[i] == holding[i]){
                return_gift[player[i]-1] = 1;
            }
        }
        
        for(i = 0; i < n; i++){
            holding[i] = hold[i];
        }

        count += 1;
        int all_return = 1;
        for(i = 0; i < n; i++){
            if (return_gift[i] == 0){
                all_return = 0;
            }
        }

        if(all_return == 1){
            break;
        }
    }
    
    printf("%d\n",count);
}