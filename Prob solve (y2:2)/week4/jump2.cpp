#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct node{
    int x;
    int y;
    int dis;
}tree_t;

int n, r;

tree_t create(int x, int y){
    tree_t tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.dis = 1e9;
    return tmp;
}

int main(){
    int i;
    cin >> n >> r;
    vector<tree_t> t;
    t.push_back(create(0,0));
    
    for(i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        t.push_back(create(tmp1,tmp2));
    }

    t.push_back(create(100,100));
    t[0].dis = 0;
    queue<int> q;
    q.push(0);
    while(q.empty() != 1){
        int tmp_q = q.front();
        //cout << "(" << t[tmp_q].x << ", " << t[tmp_q].y << ")\n";
        q.pop();
        for(i = 0; i < n+2; i++){
            int dis_x = (t[i].x - t[tmp_q].x)*(t[i].x - t[tmp_q].x);
            int dis_y = (t[i].y - t[tmp_q].y)*(t[i].y - t[tmp_q].y);
            if(dis_x + dis_y <= r*r){
                if(t[i].dis > t[tmp_q].dis + 1){
                    //cout << dis_x + dis_y << " ";
                    //cout << "---> (" << t[i].x << ", " << t[i].y << ") dis : ";
                    t[i].dis = t[tmp_q].dis + 1;
                    //cout << t[i].dis << "\n";
                    q.push(i);
                }
            }
        }
    }

    if(t[n+1].dis == 1e9){
        cout << -1;
    }else{
        cout << t[n+1].dis;
    }
    return 0;
}