#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, t;

int bfs(vector<int> g[], int s, int store[]){
    //cout << "s = " << s << "\n";
    int visit[n+1];
    int stop = 0;
    queue<int> q;
    q.push(s);
    queue<int> q2;
    int i, h=0;
    if(store[s] == 1){
        return 0;
    }
    for(i = 0; i < n+1; i++){
        visit[i] = 0;
    }
    while(!q.empty()){
        int sizeq = q.size();
        for(i = 0; i < sizeq; i++){
            int tmp = q.front();
            //cout << "  q: " << tmp << " ";
            q.pop();
            q2.push(tmp);
        }
        //cout << "\n";
        while(!q2.empty()){
            int tmp_q = q2.front();
            q2.pop();
            visit[tmp_q] = 1;
            for(i = 0; i < g[tmp_q].size(); i++){
                if(visit[g[tmp_q][i]] == 0){
                    //cout << "     " << g[tmp_q][i] << " ";
                    if(store[g[tmp_q][i]] == 1){
                        //cout << "        store : " << g[tmp_q][i] << "\n";
                        stop = 1;
                    }
                    visit[g[tmp_q][i]] = 1;
                    q.push(g[tmp_q][i]);
                }
            }
            //cout << "\n";
        }
        h++;
        if(stop == 1){
            return h;
        }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    int i;
    vector<int> graph[n+1];
    for(i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> factory;
    vector<int> ans;
    int storage[n+1];
    for(i = 0; i < s+1; i++){
        storage[i] = 0;
    }
    for(i = 0; i < s; i++){
        int tmp;
        cin >> tmp;
        storage[tmp] = 1;
    }
    /*for(i = 0; i < s+1; i++){
        cout << storage[i] << " ";
    }*/
    //cout << "\n";
    for(i = 0; i < t; i++){
        int tmp;
        cin >> tmp;
        factory.push_back(tmp);
        int result = bfs(graph,tmp,storage);
        ans.push_back(result);
    }
    /*for(i = 0; i < t; i++){
        int numfac = factory[i];
        int result = bfs(graph,numfac,storage);
        cout << result << "\n";
    }*/
    for(i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}