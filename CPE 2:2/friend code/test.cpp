#include "stdc++.h"
using namespace std;


queue<int> keep;
int dist[1010];
pair<int,int> demo[1010];
int n,r;

int shortpath(int k){
    dist[k] = 0;
    keep.push(k);
    while(!keep.empty()){
        int now = keep.front();
        keep.pop();
        /*if (now = n+1){
            printf("%d\n",dist[n+1]);
            break;
        }*/
        for (int i=1;i<=n+1;i++){
            int x1 = (demo[i].first - demo[now].first);
            int y1 = (demo[i].second - demo[now].second);
            if ((x1*x1) + (y1*y1) <= r*r){
                if (dist[now] +1 < dist[i]){
                    dist[i] = dist[now]+1;
                    keep.push(i);
                }
            }
        }
    }
}

int main(){
    int x,y,min = 1e9;
    cin >> n >> r;
    demo[0] = {0,0};
    for (int i=1;i<=n;i++){
        cin >> x >> y;
        demo[i].first = x;
        demo[i].second = y;
    }
    for (int i=0;i<=n+1;i++){
        dist[i] = 1e9;
    } 
    demo[n+1] = {100,100};
    shortpath(0);
    if (dist[n+1] == 1e9){
        cout << -1;
    }else{
        cout << dist[n+1] ;
    }
}