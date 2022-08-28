#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bipartite(vector<int> g[],int t[], int s, int *bi){
    int i;
    queue<int> q;
    q.push(s);
    t[s] = 1;
    while(!q.empty()){
        int tmp_q = q.front();
        //cout << tmp_q << " : " << t[tmp_q] << "\n";
        q.pop();
        for(i = 0; i < g[tmp_q].size(); i++){
            //cout << g[tmp_q][i] << " <<<----\n";
            if(t[g[tmp_q][i]] == 0){
                if(t[tmp_q] == 1){
                    t[g[tmp_q][i]] = 2;
                }else if(t[tmp_q] == 2){
                    t[g[tmp_q][i]] = 1;
                }
                q.push(g[tmp_q][i]);
            }else{
                if(t[g[tmp_q][i]] == t[tmp_q]){
                    *bi = 0;
                }
            }
        }
    }
}

int main(){
    int k, i, j, l;
    cin >> k;
    for(j = 0; j < k; j++){
        int n, m;
        int bi = 1;
        cin >> n >> m;
        if(n == 1){
            bi = 0;
        }
        vector<int> graph[n+1];
        int team[n+1];
        for(i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(i = 1; i <= n; i++){
            team[i] = 0;
        }
        bipartite(graph,team,1,&bi);
        if(bi == 1){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}