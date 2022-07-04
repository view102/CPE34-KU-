#include<iostream>
#include<vector>

using namespace std;

int n, r;

int jump(int jump_remain_dis, int *xp, int *yp, vector<int> t[]){
    int i;
    int max_dis_from = -1, min_dis_to = 999999;
    int tmp_x = *xp;
    int tmp_y = *yp;
    for(i = 0; i < n+1; i++){
        if(t[i][0] == *xp && t[i][1] == *yp){
            continue;
        }
        int dis_from_start = (t[i][0]-tmp_x)*(t[i][0]-tmp_x) + (t[i][1]-tmp_y)*(t[i][1]-tmp_y);
        int dis_to_end = (100-t[i][0])*(100-t[i][0]) + (100-t[i][1])*(100-t[i][1]);
        //cout << t[i][0] << ", " << t[i][1] << " -> ";
        //cout << "start = " << dis_from_start << ", end = " << dis_to_end << "\n";
        if(dis_from_start <= r*r){
            if(dis_to_end < min_dis_to){
                *xp = t[i][0];
                *yp = t[i][1];
                //max_dis_from = dis_from_start;
                min_dis_to = dis_to_end;
            }
        }
    }

    return (100-(*xp))*(100-(*xp)) + (100-(*yp))*(100-(*yp));
}

int main(){
    int i;
    cin >> n >> r;
    vector<int> tree[n+1];

    for(i = 0; i < n; i++){
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        tree[i].push_back(tmp_x);
        tree[i].push_back(tmp_y);
    }
    tree[n].push_back(100);
    tree[n].push_back(100);
    /*for(i = 0; i < n; i++){
        cout << "(" << tree[i][0] << ", " << tree[i][1] << ")\n";

    }*/

    //cout << "PASS\n";

    int x = 0, y = 0, count = 0;
    int remain_dis = (100*100)+(100*100);

    while(remain_dis != 0){
        //cout << remain_dis << " & " << count <<"\n";
        //cout << x << ", " << y << "\n";
        remain_dis = jump(remain_dis, &x, &y, tree);
        count++;
        if(x == 0 && y == 0){
            count = -1;
            break;
        }
    }
    cout << count;

    return 0;
}