#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int n, m;
int dis1[100010], dis2[100010];

void short_path_express(vector< pair< pair<int,int>, int > > graph[], int s){
    int i;
    for(i = 0; i <= n; i++){
        dis1[i] = 1e9;
        dis2[i] = 1e9;
    }
    dis1[s] = 0;
    dis2[s] = 0;
    priority_queue< pair< int, pair<int, int> >, vector< pair< int, pair<int, int> > >, greater< pair< int, pair<int, int> > > > q;
    q.push(make_pair(0,make_pair(s,0)));
    while(q.size() != 0){
        int now = q.top().second.first;
        int express = q.top().second.second;
        int w = q.top().first; 
        //cout << "(" << now << "," << express << "," << w << ") : ";
        //cout << now << " : ";
        q.pop();
        for(i = 0; i < graph[now].size(); i++){
            int status = graph[now][i].first.second;
            int node = graph[now][i].first.first;
            int node_w = graph[now][i].second;
            //cout << express << " | " << status << " , ";
            if(express == 1 && status == 1){
                continue;
            }
            if(express == 1 && status == 0){
                if(dis2[node] > dis2[now] + node_w){
                    dis2[node] = dis2[now] + node_w;
                    q.push(make_pair(dis2[node], make_pair(node, express)));
                    //cout << "(" << node << "," << status << "," << dis2[node] << ") , "; 
                }
            }else{
                if(status == 1){
                    if(dis2[node] > dis1[now] + node_w){
                        dis2[node] = dis1[now] + node_w;
                        q.push(make_pair(dis2[node], make_pair(node, status)));
                        //cout << "(" << node << "," << status << "," << dis2[node] << ") , ";
                    }
                }else{
                    if(dis1[node] > dis1[now] + node_w){
                        dis1[node] = dis1[now] + node_w;
                        q.push(make_pair(dis1[node], make_pair(node, status)));
                        //cout << "(" << node << "," << status << "," << dis1[node] << ") , ";
                    }
                }
            }
        }
        //cout << "\n";
    }
}

int main(){
    cin >> n >> m;
    vector< pair< pair<int, int> , int> > graph[n+1];
    int i;
    for(i = 0; i < m; i++){
        int a, b, w, s;
        cin >> a >> b >> w >> s;
        graph[a].push_back(make_pair(make_pair(b,s),w));
        graph[b].push_back(make_pair(make_pair(a,s),w));
    }
    short_path_express(graph, 1);
    //cout << dis1[n] << ", " << dis2[n];
    if(dis1[n] == 1e9 && dis2[n] == 1e9){
        cout << -1;
    }else{
        cout << min(dis1[n], dis2[n]);
    }
}