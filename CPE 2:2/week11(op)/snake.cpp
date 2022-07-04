#include<iostream>

using namespace std;
int n, m;

int main(){
    cin >> n >> m;
    int i;
    int data[n+1];
    data[0] = 0;
    for(i = 1; i <= n; i++){
        cin >> data[i];
    }
    int index_player = 0;
    for(i = 0; i < m; i++){
        int dice;
        cin >> dice;
        index_player += dice;
        if(index_player > n){
            index_player = n;
            continue;
        }
        //index_player += data[index_player];
        if(index_player + data[index_player] > n){
            index_player = n;
        }else if(index_player + data[index_player] < 0){
            index_player = 0;
        }else{
            index_player += data[index_player];
        }
    }
    cout << index_player;
}