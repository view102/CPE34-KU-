#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;

int travel(vector<string> v, vector<int> vis[], int x, int y ,int count, int *forest, int *element){
    vis[y][x] = 1;
    if(v[y][x] == '$'){
        *element = 1;
    }
    if(v[y][x] == '*'){
        *forest = 1;
    }
    //cout << y << " : " << x << " count = " << count << "\n";
    if(x+1 < m){
        if(v[y][x+1] != '#' && vis[y][x+1] != 1){
            count += 1;
            count = travel(v, vis, x+1, y, count, forest, element);
        }
    }
    if(y+1 < n){
        if(v[y+1][x] != '#' && vis[y+1][x] != 1){
            count += 1;
            count = travel(v, vis, x, y+1, count, forest, element);
        }
    }
    if(x-1 >= 0){
        if(v[y][x-1] != '#' && vis[y][x-1] != 1){
            count += 1;
            count = travel(v, vis, x-1, y, count, forest, element);
        }
    }
    if(y-1 >= 0){
        if(v[y-1][x] != '#' && vis[y-1][x] != 1){
            count += 1;
            count = travel(v, vis, x, y-1, count, forest, element);
        }
    }
    return count;
}

int main(){
    int i, j;
    cin >> n >> m;
    vector<int> visit[n];
    int verygood_area = 0;
    int normal_area = 0;

    vector<string> map;
    for(i = 0; i < n; i++){
        string s;
        cin >> s;
        map.push_back(s);

        for(j = 0; j < m; j++){
            visit[i].push_back(0);
        }
    }

    int count;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(visit[i][j] == 0 && map[i][j] != '#'){
                int forest = 0;
                int element = 0;
                count = travel(map, visit, j, i, 1, &forest, &element);
                if(forest == 1 && element == 1){
                    verygood_area += count;
                }else if(forest == 1 && element == 0){
                    normal_area += count;
                }else if(forest == 0 && element == 1){
                    normal_area += count;
                }
                //cout << "finish\n";
            }
        }
    }

    cout << verygood_area << " " << normal_area;
    /*int forest = 0;
    int element = 0;
    cout << travel(map, visit, 0, 0, 1, &forest, &element);
    cout << "\n" << forest << " : " << element;*/

}