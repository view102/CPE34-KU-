#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int n, m;
int dis[100010], visit[100010];
vector< pair<int, int> > g[100010];


void short_path(int s, int a, int b, int w){
    int i;
    priority_queue< pair<int,int>, vector< pair<int,int> >,greater <pair<int,int> > > q;
    g[a].push_back(make_pair(b,w));
    g[b].push_back(make_pair(a,w));
    for(i = 0; i <= n; i++){
        dis[i] = 1e9;
        visit[i] = 0;
    }
    dis[s] = 0;
    q.push(make_pair(dis[s],s));
    while(q.size() != 0){
        int tmp = q.top().second;
        q.pop();
        //visit[tmp] = 1;
        //cout << tmp << " : ";
        for(i = 0; i < g[tmp].size(); i++){
            if(dis[g[tmp][i].first] > dis[tmp] + g[tmp][i].second /*&& visit[g[tmp][i].first] == 0*/){
                dis[g[tmp][i].first] = dis[tmp] + g[tmp][i].second;
                q.push(make_pair(dis[g[tmp][i].first],g[tmp][i].first));
                //cout << g[tmp][i].first << " // " << dis[g[tmp][i].first] << "\n";
                //cout << g[tmp][i].first << ", ";
            }
        }
        //cout << "\n";
    }
    cout << "\n";
    g[a].pop_back();
    g[b].pop_back();
    
}

int main(){
    int i;
    cin >> n >> m;
    //vector< pair<int, int> > graph[n+1];
    vector< pair< pair<int, int> , int> > option;
    for(i = 0; i < m; i++){
        int s, t, w, o;
        cin >> s >> t >> w >> o;
        if(o == 0){
            g[s].push_back(make_pair(t,w));
            g[t].push_back(make_pair(s,w));
        }else{
            option.push_back(make_pair(make_pair(s,t),w));
        }
    }
    //cout << graph[1][0].first << " = " << graph[1][0].second;
    //cout << option.size();
    int min = 1e9;
    for(i = 0; i < option.size(); i++){
        short_path(1, option[i].first.first, option[i].first.second, option[i].second);
        //cout << dis[n] << "\n";
        if(min > dis[n]){
            min = dis[n];
        }
    }
    short_path(1, 0, 0, 0);
    if(min > dis[n]){
        min = dis[n];
    }
    if(min == 1e9){
        cout << -1;
    }else{
        cout << min;
    }
}
