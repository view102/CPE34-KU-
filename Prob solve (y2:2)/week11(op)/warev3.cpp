#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, k;
bool can_go;
int parent[100010];

int main(){
    cin >> n >> m >> k;
    vector<int> g[n+10];
    int i;
    for(i = 0; i <= n; i++){
        parent[i] = i;
    }
    for(i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
        while(parent[s] != s){
            s = parent[s];
        }
        while(parent[t] != t){
            t = parent[t];
        }
        if(parent[s] < parent[t]){
            parent[t] = s;
        }
    }
    for(i = 0; i < k; i++){
        int s, t;
        cin >> s >> t;
        while(parent[s] != s){
            s = parent[s];
        }
        while(parent[t] != t){
            t = parent[t];
        }
        if(parent[s] == parent[t]){
            can_go = true;
        }else{
            can_go = false;
        }
        if(!can_go){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }
}