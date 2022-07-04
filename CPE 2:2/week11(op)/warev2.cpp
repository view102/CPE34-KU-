#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, k;
bool can_go;
int visit[100010];

void bfs(vector<int> g[], int s, int t){
    queue<int> q;
    int i;
    for(i = 0; i <= n; i++){
        visit[i] = 0;
    }
    q.push(s);
    visit[s] = 1;
    while(q.size() != 0){
        int tmp = q.front();
        q.pop();
        for(i = 0; i < g[tmp].size(); i++){
            if(g[tmp][i] == t){
                visit[t] = 1;
                return;
            }
            if(visit[g[tmp][i]] == 0){
                q.push(g[tmp][i]);
                visit[g[tmp][i]] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    vector<int> g[n+10];
    int i;
    for(i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    for(i = 0; i < k; i++){
        int s, t;
        cin >> s >> t;
        can_go = false;
        bfs(g,s,t);
        if(visit[t] == 0){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }
}