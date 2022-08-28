#include<iostream>
#include<vector>

using namespace std;

int n, m;

void dfs(int v, vector<int> g[], int vis[]){
    int i;
    if(vis[v] != 1){
        //cout << v << " ";
        vis[v] = 1;
        for(i=0;i<g[v].size();i++){
            dfs(g[v][i], g, vis);
        }
    }
}

int main(){
    cin >> n >> m;
    int i, j;
    vector<int> graph[n+1];
    int visit[n+1];
    for(i = 1; i <= n; i++){
        visit[i] = 0;
    }
    for(i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int count = 0;
    for(i = 1; i <= n; i++){
        if(visit[i] != 1){
            dfs(i,graph,visit);
            count += 1;
        }
    }
    cout << count;
    /*for(i = 1; i <= n; i++){
        cout << "(" << i << ") -->";
        for(j = 0; j < graph[i].size(); j++){
            cout << "(" << i << ", " << graph[i][j] << ") ";
        }
        cout << "\n";
    }*/


}