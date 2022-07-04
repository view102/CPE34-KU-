#include<iostream>
#include<utility>

using namespace std;
int c, n, k;

int main(){
    cin >> c;
    int i, j, x, y;
    for(i = 0; i < c; i++){
        cin >> n >> k;
        int dp[n+10][2][k+1];
        pair< int, int > data[n+1];
        for(x = 1; x <= n; x++){
            int ta, to;
            cin >> ta >> to;
            data[x] = make_pair(ta, to);
        }
        for(j = 0; j <= n+1; j++){
            for(x = 0; x < 2; x++){
                for(y = 0; y < k+1; y++){
                    dp[j][x][y] = 0;
                }
            }
        }
        for(j = 1; j <= n; j++){
            for(x = 0; x < 2; x++){
                for(y = 0; y <= k; y++){
                    int first, second;
                    if(y == 0){
                        if(x == 0){
                            first = dp[j-1][1][y+1] + data[j].first;
                            second = dp[j-1][0][y+1] + data[j].first;
                        }else{
                            first = dp[j-1][0][y+1] + data[j].second;
                            second = dp[j-1][1][y+1] + data[j].second;
                        }
                    }else if(y < 2){
                        if(x == 0){
                            first = dp[j-1][0][y+1] + data[j].first;
                            second = dp[j-1][1][y-1] + data[j].first;
                        }else{
                            first = dp[j-1][1][y+1] + data[j].second;
                            second = dp[j-1][0][y-1] + data[j].second;
                        }
                    }else{
                        if(x == 0){
                            first = dp[j-1][1][y-1] + data[j].first;
                            second = dp[j-1][1][y-1] + data[j].first;
                        }else{
                            first = dp[j-1][0][y-1] + data[j].second;
                            second = dp[j-1][0][y-1] + data[j].second;
                        }
                    }
                    dp[j][x][y] = min(first, second);
                    //cout << j << "," << x << "," << y << " : " << first << "/" << second << " : ";
                    //cout << dp[j][x][y] << "\n";
                }
            }
        }
        cout << min(dp[n][0][k],dp[n][1][k]) << "\n";
    }
}