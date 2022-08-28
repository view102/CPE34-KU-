#include<iostream>

using namespace std;
int n, m, k;
int dp[210][210][210];
int data[210][210];

int main(){
    cin >> n >> m >> k;
    int i, j, t;
    for(i = 0; i <= n+1; i++){
        for(j = 0; j <= m+1; j++){
            for(t = 0; t <= k; t++){
                dp[i][j][t] = 0;
            }
        }
    }
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
    /*for(i = 1; i <= m; i++){
        int ans = recurrence(1,i,k);
        cout << ans << " ";
    }*/
    //cout << "-----------\n";
    for(t = 0; t <= k; t++){
        for(i = n; i > 0; i--){
            for(j = 1; j <= m; j++){
                //cout << t << "," << i << "," << j << " // ";
                if(t > 0){
                    int left = dp[i+1][j-1][t-1] + data[i][j];
                    int right = dp[i+1][j+1][t-1] + data[i][j];
                    int mid = dp[i+1][j][t] + data[i][j];
                    //cout << left << ", " << mid << ", " << right << "\n";
                    dp[i][j][t] = max(left,max(right,mid));
                }else{
                    dp[i][j][t] = dp[i+1][j][t] + data[i][j];
                }
                //cout << dp[i-1][j][t] << " + " << data[i][j] << " : "; 
            }
            //cout << "\n";
        }
    }
    int max = -1e9;
    for(t = 0; t <= k; t++){
        //cout << "K = " << t << "\n";
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(max < dp[i][j][t]){
                    max = dp[i][j][t];
                }
                //cout << dp[i][j][t] << " ";
            }
            //cout << "\n";
        }
    }
    cout << max;
}