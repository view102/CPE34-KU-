#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;

void topological(vector<int> g[], int deg[]){
    queue<int> q;
    int i;
    for(i = 1; i <= n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tmp_q = q.front();
        q.pop();
        cout << tmp_q << "\n";
        for(i = 0; i < g[tmp_q].size(); i++){
            deg[g[tmp_q][i]] -= 1;
            if(deg[g[tmp_q][i]] == 0){
                q.push(g[tmp_q][i]);
            }
        }
    }
}

int main(){
    int i;
    cin >> n >> m;
    vector<int> graph[n+1];
    int in_degree[n+1];
    for(i = 1; i <= n; i++){
        in_degree[i] = 0;
    }

    for(i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        in_degree[to] += 1;
    }

    /*for(i = 1; i <= n; i++){
        cout << in_degree[i] << " ";
    }*/
    int topo = 0;
    for(i = 1; i <= n; i++){
        if(in_degree[i] == 0){
            topo = 1;
        } 
    }
    if(topo){
        topological(graph,in_degree);
    }else{
        cout << "no";
    }
    return 0;
}