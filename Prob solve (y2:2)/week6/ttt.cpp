#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
int n, m;
vector< pair<int, int> > edge;
int color[1010], visit[1010];

void clear(){
    int i;
    for(i = 0; i < n; i++){
        visit[i] = 0;
        color[i] = 0;
    }
    color[1] = 1;
}

int bipatile(int x){
    int i;
    vector<int> graph[n+1];
    for(i = 0; i < m; i++){
        if(i == x){
            continue;
        }
        int a = edge[i].first;
        int b = edge[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    clear();
    queue<int> q;
    q.push(1);
    while(q.size() != 0){
        int tmp_q = q.front();
        q.pop();
        visit[tmp_q] = 1;
        for(i = 0; i < graph[tmp_q].size(); i++){
            if(visit[graph[tmp_q][i]] == 0){
                visit[graph[tmp_q][i]] = 1;
                q.push(graph[tmp_q][i]);
                if(color[tmp_q] == 1){
                    color[graph[tmp_q][i]] = 2;
                }else{
                    color[graph[tmp_q][i]] = 1;
                }
            }else{
                if(color[tmp_q] == color[graph[tmp_q][i]]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    cin >> n >> m;
    int i;
    for(i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge.push_back(make_pair(a,b));
    }
    for(i=0;i<m;i++){
        int check = bipatile(i);
        if(check == 1){
            cout << edge[i].first << " " << edge[i].second;
            break;
        }
    }
}