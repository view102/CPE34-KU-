#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<queue>
#include<cstdio>

using namespace std;
int n;
double dis[100010], visit[100010];

void create_edge(vector< pair< int, double> > graph[], int s, int t, double w){
    graph[s].push_back(make_pair(t,w));
    graph[t].push_back(make_pair(s,w));
}

void short_path(vector< pair<int,double> > g[], int s){
    int i;
    priority_queue< pair<double,int>, vector< pair<double,int> >,greater <pair<double,int> > > q;
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
    cin >> n;
    int i, j;
    int x[n+1];
    int y[n+1];
    vector< pair< int, double > > graph[n+1];
    for(i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
        for(j = 1; j < i; j++){
            double w;
            int xx = x[i] - x[j];
            int yy = y[i] - y[j];
            w = double(sqrt(xx*xx + yy*yy));
            create_edge(graph, i, j, w);
        }
    }
    /*for(i = 1; i <= n; i++){
        cout << "(" << x[i] << "," << y[i] << ") : ";
        for(j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ,";
        }
        cout << "\n";
    }*/
    short_path(graph, 1);
    double sum = 0;
    double max = -1e9;
    for(i = 1; i <= n; i++){
        //cout << dis[i] << " ";
        sum += dis[i];
        if(max < dis[i]){
            max = dis[i];
        }
    }
    sum -= max;
    //cout.precision(5);
    //cout << sum;
    printf("%.5f", sum);
}