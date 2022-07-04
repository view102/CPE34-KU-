#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int n, m;
int dis[100010], visit[100010];
int connect[100010] = {0};

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
    cin >> n >> m;
    int i, j;
    vector< pair< int, int> > graph[n+1];
    for(i = 1; i < n+1; i++){
        connect[i] = i;
    }
    for(i = 0; i < m; i++){
        int s, f, w, check = 1;
        cin >> s >> f >> w;
        graph[s].push_back(make_pair(f,w));
        graph[f].push_back(make_pair(s,w));
        while(connect[s] != s){
            s = connect[s];
        }
        while(connect[f] != f){
            f = connect[f];
        }
        if(s < f){
            connect[f] = s;
        }else{
            connect[s] = f;
        }
        for(j = 1; j <= n; j++){
            int tmp = j;
            while(connect[tmp] != tmp){
                tmp = connect[tmp];
            }
            if(connect[tmp] != 1){
                check = 0;
            }
        }
        if(check == 0){
            cout << -1 << "\n";
            continue;
        }
        short_path(graph,1);
        int sum = 0;
        for(j = 1; j <= n; j++){
            if(dis[j] != 1e9){
                sum += dis[j];
            }
        }
        cout << sum << "\n";
    }
}
