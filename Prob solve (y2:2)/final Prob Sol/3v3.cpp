#include<iostream>

using namespace std;
int n, m, k;
int dp[210][210][210];
int data[210][210];

int recurrence(int row, int col, int time){
    if(row == n+1){
        return 0;
    }else if(col == 0){
        return 0;
    }else if(col == m+1){
        return 0;
    }

    if(time > 0){
        int left = recurrence(row+1, col-1, time-1) + data[row][col];
        int right = recurrence(row+1, col+1, time-1) + data[row][col];
        int mid = recurrence(row+1, col, time) + data[row][col];
        if(left > right){
            if(left > mid){
                return dp[row][col][time] = left;
            }else{
                return dp[row][col][time] = mid;
            }
        }else{
            if(right > mid){
                return dp[row][col][time] = right;
            }else{
                return dp[row][col][time] = mid;
            }
        }
        
    }else{
        return dp[row][col][time] = recurrence(row+1, col, time) + data[row][col];
    }
    

}

int main(){
    cin >> n >> m >> k;
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> data[i][j];
        }
    }
    /*for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }*/
    int maxans = -1e9;
    for(i = 1; i <= m; i++){
        if(maxans < recurrence(1,i,k)){
            maxans = recurrence(1,i,k);
        }
    }
    cout << max;
}