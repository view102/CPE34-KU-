#include<iostream>
#include<vector>

using namespace std;
int parent[100010], h[100010];
int N, Q;

int main(){
    cin >> N >> Q;
    int i;
    for(i = 0; i < N; i++){
        parent[i] = i;
        h[i] = 0;
    }
    for(i = 0; i < Q; i++){
        char command;
        int x, y, cx = 0, cy = 0;
        cin >> command >> x >> y;
        while(x != parent[x]){
            x = parent[x];
        }
        while(y != parent[y]){
            y = parent[y];
        }
        if(command == 'q'){
            if(x == y){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else if(command == 'c'){
            if(h[x] > h[y]){
                parent[y] = x;
            }else if(h[x] < h[y]){
                parent[x] = y;
            }else{
                parent[y] = x;
                h[y]++;
            }
        }
    }
}