#include<iostream>
#include<vector>

using namespace std;
int n, k;
int visit[20][20];
int check = 0;

void check_jump(vector<int> map[], int x, int y){
    //cout << x << ", " << y << " : " << map[x][y] << "\n";
    visit[x][y] = 1;
    if(x == n-1 && y == n-1){
        check = 1;
    }
    if(y+1 < n && map[x][y+1] <= map[x][y]+k && visit[x][y+1] == 0){
        check_jump(map, x, y+1);
    }
    if(x+1 < n && map[x+1][y] <= map[x][y]+k && visit[x+1][y] == 0){
        check_jump(map, x+1, y);
    }
    if(x-1 >= 0 && map[x-1][y] <= map[x][y]+k && visit[x-1][y] == 0){
        check_jump(map, x-1, y);
    }
    if(y-1 >= 0 && map[x][y-1] <= map[x][y]+k && visit[x][y-1] == 0){
        check_jump(map, x, y-1);
    }
}

int main(){
    cin >> n >> k;
    int i, j, a;
    vector<int> map_game[n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> a;
            map_game[i].push_back(a);
            visit[i][j] = 0;
        }
    }
    check_jump(map_game, 0, 0);
    if(check == 1){
        cout << "yes";
    }else{
        cout << "no";
    }
    /*for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << map_game[i][j] << " ";
        }
        cout << "\n";
    }*/
}