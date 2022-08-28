#include<iostream>

using namespace std;
int l, n;
int dp[1010][1010];
int cut[1010];

int solve_cost(int s, int f){  
    if(dp[s][f] != 1e9){
        return dp[s][f];
    }
    int cost_min = 1e9;
    for(int i = s+1; i < f; i++){
        if(cut[i] == 1){
            int cost = f - s + solve_cost(s, i) + solve_cost(i, f);
            if(cost_min > cost){
                cost_min = cost;
            }
        }
    }
    if(cost_min == 1e9){
        dp[s][f] = 0;
        return 0;
    }else{
        dp[s][f] = cost_min;
        return cost_min;
    }

}

int main(){
    while(cin >> l && l){
        cin >> n;
        int i, j;
        int cut_index[n];
        for(i = 0; i <= l+1; i++){
            cut[i] = 0;
            for(j = 0; j <= l+1; j++){
                dp[i][j] = 1e9;
            }
        }
        for(i = 0; i < n; i++){
            cin >> cut_index[i];
            cut[cut_index[i]] = 1;
        }
        int opt = solve_cost(0, l);
        cout << "The minimum cutting is " << opt << ".\n";
    }
}