#include<iostream>

using namespace std;
int T;

int main(){
    cin >> T;
    int i, j;
    while(T--){
        int n, p, w, g, mw;
        int result = 0;
        int dp[40];
        for(i = 0; i < 40; i++){
            dp[i] = 0;
        }
        cin >> n;
        for(i = 0; i < n; i++){
            cin >> p >> w;
            for(j = 39; j >= w; j--){
                if(dp[j-w] + p > dp[j]){
                    dp[j] = dp[j-w] + p;
                }
            }
        }
        cin >> g;
        for(i = 0; i < g; i++){
            cin >> mw;
            result += dp[mw];
        }
        cout << result << "\n";
    }
}