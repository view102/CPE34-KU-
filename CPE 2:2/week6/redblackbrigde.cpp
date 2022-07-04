#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int dis[50010], visit[50010];

void clear(int s){
    int i;
    for(i=0;i<=n;i++){
        visit[i] = 0;
        if(i == s){
            dis[i] = 0;
            continue;
        }
        dis[i] = 1e9;
    }
}

int shortest_path(vector<int> graph[], int s, int t){
    clear(s);
    queue<int> q;
    int i;
    q.push(s);
    while(q.size() != 0){
        int tmp_q = q.front();
        visit[tmp_q] = 1;
        q.pop();
        for(i=0;i<graph[tmp_q].size();i++){
            if(visit[graph[tmp_q][i]] == 0){
                visit[graph[tmp_q][i]] = 1;
                q.push(graph[tmp_q][i]);
                if(dis[graph[tmp_q][i]] > dis[tmp_q] + 1){
                    dis[graph[tmp_q][i]] = dis[tmp_q] + 1;
                }
            }
        }
    }
    return dis[t];
}

int main(){
    int s, t;
    cin >> n >> m >> s >> t;
    vector<int> red[n+1];
    vector<int> black[n+1];
    int i;
    for(i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1){
            red[a].push_back(b);
            red[b].push_back(a);
        }else if(c == 2){
            black[a].push_back(b);
            black[b].push_back(a);
        }else{
            red[a].push_back(b);
            red[b].push_back(a);
            black[a].push_back(b);
            black[b].push_back(a);
        }
    }
    /*for(i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < black[i].size(); j++){
            cout << black[i][j] << " ";
        }
        cout << "\n";
    }*/
    int red_dis = shortest_path(red,s,t);
    int black_dis = shortest_path(black,s,t);
    if(red_dis < black_dis){
        if(red_dis != 1e9){
            cout << red_dis;
        }else{
            cout << -1;
        }
    }else{
        if(black_dis != 1e9){
            cout << black_dis;
        }else{
            cout << -1;
        }
    }
}