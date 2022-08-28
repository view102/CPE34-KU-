#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>

using namespace std;

int n, m;
//vector<int> color, visit;

bool bipartite(vector<int> g[], int u, int v, vector<int> &color, vector<int> &visit){
    queue<int> q;
    int i;
    q.push(u);
    while(!q.empty()){
        int tmp_q = q.front();
        q.pop();
        visit[tmp_q] = 1;
        //cout << " " << tmp_q << " :\n";
        for(i = 0; i < g[tmp_q].size(); i++){
            //cout << "  (" << tmp_q << ", " << g[tmp_q][i] << ")\n";
            //cout << "  visit(" << visit[tmp_q] << ", " << visit[g[tmp_q][i]] << ")\n";
            if(visit[g[tmp_q][i]] == 0){
                //visit[g[tmp_q][i]] = 1;
                if(color[tmp_q] == 1){
                    color[g[tmp_q][i]] = 2;
                }else{
                    color[g[tmp_q][i]] = 1;
                }
                q.push(g[tmp_q][i]);
            }else{
                if(color[g[tmp_q][i]] == color[tmp_q]){
                    //cout << "Color " << g[tmp_q][i] << "(" << color[g[tmp_q][i]] << ") : " << tmp_q << " ->" << color[tmp_q] << "\n";
                    return false;
                }
            }
        } 
    }
    return true;
}

int main(){
    cin >> n >> m;
    vector<int> color, visit;
    int i, result = 0, count = 0, Error = 0;
    int j;
    for(i = 0; i <= n; i++){
        color.push_back(0);
        visit.push_back(0);
    }
    int bi = 1;
    vector<int> graph[n+1];
    for(i = 0; i < m; i++){
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
        if(color[p1] == 0 && color[p2] == 0){
            color[p1] = 1;
            color[p2] = 2;
            visit[p1] = 1;
            visit[p2] = 1;
            //cout << "Case1: " << p1 << " = " << color[p1] << ", " << p2 << " = " << color[p2] << "\n";
        }else if(color[p1] == 0){
            if(color[p2] == 1){
                color[p1] = 2;
            }else{
                color[p1] = 1;
            }
            visit[p1] = 1;
            //cout << "Case2: " << p1 << " = " << color[p1] << ", " << p2 << " = " << color[p2] << "\n";
        }else if(color[p2] == 0){
            if(color[p1] == 1){
                color[p2] = 2;
            }else{
                color[p2] = 1;
            }
            visit[p2] = 1;
            //cout << "Case3: " << p1 << " = " << color[p1] << ", " << p2 << " = " << color[p2] << "\n";
        }else{
            //cout << "Case4before: " << p1 << " = " << color[p1] << ", " << p2 << " = " << color[p2] << "\n";
            if(color[p1] == color[p2]){
                queue<int> tmp;
                tmp.push(p1);
                while(!tmp.empty()){
                    int front = tmp.front();
                    tmp.pop();
                    for(j = 0; j < graph[front].size(); j++){
                        if(color[graph[front][j]] != 0){
                            color[graph[front][j]] = 0;
                            tmp.push(graph[front][j]);
                        }
                    }
                } 
                for(j = 1; j <= n; j++){
                    visit[j] = 0;
                }
                color[p1] = 1;
                //visit[p1] = 1;
                if(!bipartite(graph,p1,p2,color,visit)){
                    if(result == 0){
                        Error = 1;
                        //cout << p1 << ", " << p2 << " Error.\n";
                        result = count;
                    }
                }
                //cout << "Case4after: " << p1 << " = " << color[p1] << ", " << p2 << " = " << color[p2] << "\n";
            }
        }
        count++;
        /*for(j = 1; j <= n; j++){
            visit[j] = 0;
            color[j] = 0;
        }*/
    }
    if(Error == 0){
        result = count;
    }
    cout << result;
    return 0;
}
