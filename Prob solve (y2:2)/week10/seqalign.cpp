#include<iostream>

using namespace std;
string x, y;
int dp[1010][1010];

int main(){
    cin >> x;
    cin >> y;
    int size_x = x.size();
    int size_y = y.size();
    int i, j;
    for(i = 0; i <= size_x+1; i++){
        for(j = 0; j <= size_y+1; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    for(j = 1; j <= size_y; j++){
        dp[0][j] = 1 + dp[0][j-1];
    }
    for(i = 1; i <= size_x; i++){
        dp[i][0] = 1 + dp[i-1][0];
    }
    for(i = 1; i <= size_x; i++){
        for(j = 1; j <= size_y; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
    }
    /*for(i = 1; i <= size_x; i++){
        for(j = 1; j <= size_y; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[size_x][size_y];
}