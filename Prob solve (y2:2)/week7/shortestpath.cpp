#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int weight[1000][1000];

int find_min(int visit[], int dis[]){
    int i, min = 1e9, node;
    for(i = 1; i < n+1; i++){
        if(dis[i] < min && visit[i] == 0){
            min = dis[i];
            node = i;
        }
    }
    return node;
}

int shortestpath(vector<int> g[], int s){
    int i;
    int visit[n+1];
    int dis[n+1];
    //cout << g[3][0] << " check\n";
    for(i = 0; i < n+1; i++){
        visit[i] = 0;
        dis[i] = 1e9;
    }
    dis[s] = 0;
    visit[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size() != 0){
        int tmp = q.front();
        //cout << tmp << " is tmp\n"; 
        q.pop();
        //cout << g[tmp].size() << " is size\n";
        for(i = 0; i < g[tmp].size(); i++){
            if(dis[g[tmp][i]] > dis[tmp] + weight[tmp][g[tmp][i]]){
                dis[g[tmp][i]] = dis[tmp] + weight[tmp][g[tmp][i]];
            }
        }
        //cout << "CHECK\n";
        int min_vertex = find_min(visit,dis);
        //cout << "CHECK\n";
        //cout << min_vertex << " = " << dis[min_vertex] << "\n";
        if(min_vertex > 0 && min_vertex <= n){
            q.push(min_vertex);
            visit[min_vertex] = 1;
        }
    }
    return dis[n];
}

int main(){
    int i;
    cin >> n >> m;
    vector<int> graph[n+1];
    for(i = 0; i < m; i++){
        int s, t, w;
        cin >> s >> t >> w;
        graph[s].push_back(t);
        graph[t].push_back(s);
        weight[s][t] = w;
        weight[t][s] = w;
    }
    //cout << graph[3][0];
    int x = shortestpath(graph, 1);
    cout << x;
}