#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int n, m, c;
int dis[100010];

void short_path(vector< pair<int,int> > g[], int s){
    int i;
    queue<int> q;
    for(i = 0; i <= n; i++){
        dis[i] = 1e9;
    }
    dis[s] = 0;
    q.push(s);
    while(q.size() != 0){
        int tmp = q.front();
        //cout << tmp << " : ";
        q.pop();
        for(i = 0; i < g[tmp].size(); i++){
            if(dis[g[tmp][i].first] > dis[tmp] + g[tmp][i].second){
                dis[g[tmp][i].first] = dis[tmp] + g[tmp][i].second;
                q.push(g[tmp][i].first);
                //cout << g[tmp][i].first << " // " << dis[g[tmp][i].first] << "\n";
                //cout << g[tmp][i].first << ", ";
            }
        }
        //cout << "\n";
    }
    //cout << "\n";
}

int main(){
    int i, j;
    cin >> c;
    for(j = 0; j < c; j++){
        int s, t;
        cin >> n >> m >> s >> t;
        vector< pair<int, int> > graph[n+1];
        for(i = 0; i < m; i++){
            int s, t, w;
            cin >> s >> t >> w;
            graph[s].push_back(make_pair(t,w));
            graph[t].push_back(make_pair(s,w));
        }
        //cout << graph[1][0].first << " = " << graph[1][0].second;
        short_path(graph, s);
        if(dis[t] != 1e9){
            cout << "Case #" << j+1 << ": " << dis[t] << "\n";
        }else{
            cout << "Case #" << j+1 << ": unreachable\n";
        }
    }
}
