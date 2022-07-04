#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, t;

void shortest(vector<int> g[], int s, int dis[],int disa[], vector<int> fac){
    int visit[n+1];
    int i;
    for(i = 0; i < n+1; i++){
        if(i == s){
            //dis[i] = 0;
            visit[i] = 0;
            continue;
        }
        //dis[i] = 1e9;
        visit[i] = 0;
    }

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        //cout << q.front() << " ";
        int tmp = q.front();
        q.pop();
        visit[tmp] = 1;
        for(i = 0; i < g[tmp].size(); i++){
            if(visit[g[tmp][i]] == 0){
                visit[g[tmp][i]] = 1;
                if(dis[g[tmp][i]] > dis[tmp] + 1){
                    dis[g[tmp][i]] = dis[tmp] + 1;
                }
                q.push(g[tmp][i]);
            }
        }
    }
    //cout << "\n";
    //cout << " fac : " << dis[1] << " " << dis[6] << " " << dis[5] << " " << dis[4] << " " << dis[7] << " \n";
    for(i = 0; i < t; i++){
        //cout << fac[i] << ": ";
        //cout << dis[fac[i]] << ", " << disa[fac[i]];
        if(disa[fac[i]] > dis[fac[i]]){
            //cout << dis[fac[i]] << ", " << disa[fac[i]];
            disa[fac[i]] = dis[fac[i]];
        }
        //cout << "\n";
    }
}

int main(){
    cin >> n >> m >> s >> t;
    int i;
    int dis[n+1];
    int disa[n+1];
    for(i = 0; i < n+1; i++){
        disa[i] = 100010;
    }
    vector<int> graph[n+1];
    for(i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> factory;
    vector<int> ans;
    vector<int> st;
    int storage[n+1];
    for(i = 0; i < s+1; i++){
        storage[i] = 0;
    }
    for(i = 0; i < s; i++){
        int tmp;
        cin >> tmp;
        storage[tmp] = 1;
        st.push_back(tmp);
    }
    /*for(i = 0; i < s+1; i++){
        cout << storage[i] << " ";
    }*/
    //cout << "\n";
    for(i = 0; i < t; i++){
        int tmp;
        cin >> tmp;
        factory.push_back(tmp);
    }
    int j;
    for(i = 0; i < s; i++){
        for(j = 0; j < n+1; j++){
            if(j == st[i]){
                dis[j] = 0;
                //visit[i] = 0;
                continue;
            }
            dis[j] = 1e9;
            //visit[i] = 0;
        }
        shortest(graph,st[i],dis,disa,factory);
        //cout << "\n";
    }
    //cout << " fac : " << disa[1] << " " << disa[6] << " " << disa[5] << " " << disa[4] << " " << disa[7] << " ";
    for(i = 0; i < t; i++){
        cout << disa[factory[i]] << "\n";
    }
}