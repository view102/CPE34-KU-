#include<iostream>
#include<vector>

using namespace std;
 
int n, m;
char new_map[30][30];
int visit[30][30];
bool pass = false;

void create_new_map(vector<char> oldmap[]){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < m-1; j++){
            if(oldmap[i][j] == '.' && oldmap[i][j+1] == '.' && oldmap[i+1][j] == '.' && oldmap[i+1][j+1] == '.'){
                new_map[i][j] = '.';
            }else{
                new_map[i][j] = '#';
            }
        }
    }
}

void clear_visit(){
    int i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 30; j++){
            visit[i][j] = 0;
        }
    }
}

void travel(int x, int y, bool *pass){
    //cout << "(x,y): " << x << ", " << y << "\n";
    if(x == n-2 && new_map[x][y] == '.'){
        *pass = true;
    }
    visit[x][y] = 1;
    if(x>0 && new_map[x-1][y] == '.' && visit[x-1][y] == 0){
        travel(x-1,y,pass);
    }
    if(y>0 && new_map[x][y-1] == '.' && visit[x][y-1] == 0){
        travel(x,y-1,pass);
    }
    if(x<n-2 && new_map[x+1][y] == '.' && visit[x+1][y] == 0){
        travel(x+1,y,pass);
    }
    if(y<m-2 && new_map[x][y+1] == '.' && visit[x][y+1] == 0){
        travel(x,y+1,pass);
    }
}

int main(){
    cin >> n >> m;
    vector<char> map[n];
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            char c;
            cin >> c;
            map[i].push_back(c);
        }
    }
    /*for(i = 0; i < n; i++){
        cout << i << ": ";
        for(j = 0; j < m; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }*/
    create_new_map(map);

    /*for(i = 0; i < n-1; i++){
        cout << "new: ";
        for(j = 0; j < m-1; j++){
            cout << new_map[i][j];
        }
        cout << "\n";
    }*/

    int pass = 0;
    for(i = 0; i < m-1; i++){
        if(new_map[0][i] == '.'){
            clear_visit();
            bool tmp = false;
            travel(0,i,&tmp);
            if(tmp == true){
                pass = 1;
            }
        }
    }

    if(pass){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }

    return 0;
}
/*
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.
*/