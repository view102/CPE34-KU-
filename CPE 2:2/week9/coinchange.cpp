#include<iostream>

using namespace std;
int dp[8000];
int cent[4];

int main(){
    int i, j;
    cent[0] = 5; cent[1] = 10; cent[2] = 25; cent[3] = 50;
    for(i = 0; i < 5; i++){
        dp[i] = 1;
    }
    for(i = 5; i < 8000; i++){
        dp[i] = dp[i-1];
    }
    for(i = 0; i < 4; i++){
        for(j = cent[i]; j < 8000; j++){
            dp[j] = dp[j] + dp[j-cent[i]];
        }
    }
    int n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }
}