#include<iostream>
#include<utility>

using namespace std;
int c, n, k;

int main(){
    cin >> c;
    int i, j, x, y;
    for(i = 0; i < c; i++){
        cin >> n >> k;
        int dp[n+2][k+1];
        pair< int, int > data[n+1];
        for(x = 1; x <= n; x++){
            int ta, to;
            cin >> ta >> to;
            data[x] = make_pair(ta, to);
        }
        for(j = 0; j <= n+1; j++){
            for(x = 0; x <= k; x++){
                dp[j][x] = 0;
            }
        }
        for(j = n; j > 0; j--){
            for(x = 0; x <= k; x++){
                if(x = 0){
                    
                }
            }
        }
    }
}