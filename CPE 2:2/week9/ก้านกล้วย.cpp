#include<iostream>

using namespace std;
int n;

int main(){
    cin >> n;
    int dp[n+1];
    int data[n+1];
    int i, maxans = -1e9;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    for(i = 1; i <= n; i++){
        cin >> data[i];
        if(i == 1){
            continue;
        }else if(i == 2){
            continue;
        }
        int first = dp[i-3] + data[i];
        int second = dp[i-1];
        dp[i] = max(first,second);
        if(maxans < dp[i]){
            maxans = dp[i];
        }
    }
    cout << maxans;
}