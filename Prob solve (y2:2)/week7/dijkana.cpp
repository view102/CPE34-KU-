#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<pair<int,int> > demo[100100];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater <pair<int,int> > > keep;
vector<int> dist(100100,1e9);

void shortpath(int start){
    dist[start] = 0;
    keep.push(make_pair(dist[start],start));
    while(!keep.empty()){
        int k1 = keep.top().first , k2 = keep.top().second;
        cout << k2 << " : ";
        keep.pop();
        for (int i=0;i<demo[k2].size();i++){
            int v = demo[k2][i].first ,w = demo[k2][i].second;
            if(dist[k2] + w < dist[v]){
                dist[v] = dist[k2] + w;
                keep.push(make_pair(dist[v],v));
                cout << v << ", ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}
int main(){
    int m,n,u,v,w;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        demo[u].push_back(make_pair(v,w));
        demo[v].push_back(make_pair(u,w));

    }
    shortpath(1);
    cout << dist[n] << endl;
} 