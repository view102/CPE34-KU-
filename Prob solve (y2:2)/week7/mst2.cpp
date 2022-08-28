#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int n, m;
int dis[100010], visit[100010];

void short_path(vector< pair<int,int> > g[], int s){
    int i;
    priority_queue< pair<int,int>, vector< pair<int,int> >,greater <pair<int,int> > > q;
    //queue<int> q;
    for(i = 0; i <= n; i++){
        dis[i] = 1e9;
        visit[i] = 0;
    }
    dis[s] = 0;
    //visit[s] = 1;
    q.push(make_pair(dis[s],s));
    while(q.size() != 0){
        int tmp = q.top().second;
        //cout << tmp << " : ";
        q.pop();
        visit[tmp] = 1;
        for(i = 0; i < g[tmp].size(); i++){
            if(dis[g[tmp][i].first] > g[tmp][i].second && visit[g[tmp][i].first] == 0){
                dis[g[tmp][i].first] = g[tmp][i].second;
                q.push(make_pair(dis[g[tmp][i].first],g[tmp][i].first));
                //cout << g[tmp][i].first << " // " << dis[g[tmp][i].first] << "\n";
                //cout << g[tmp][i].first << ", ";
            }
        }
        //cout << "\n";
    }
    //cout << "\n";
}

int main(){
    int i, sum_cost = 0;
    cin >> n >> m;
    vector< pair<int, int> > graph[n+1];
    for(i = 0; i < m; i++){
        int s, t, w;
        cin >> s >> t >> w;
        graph[s].push_back(make_pair(t,w));
        graph[t].push_back(make_pair(s,w));
    }
    //cout << graph[1][0].first << " = " << graph[1][0].second;
    short_path(graph, 1);
    int sum = 0;
    for(i = 1; i <= n; i++){
        sum += dis[i];
    }
    cout << sum;
}
