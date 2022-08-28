#include<iostream>
#include<vector>

using namespace std;
int parent[100010];
int N, Q;

int main(){
    cin >> N >> Q;
    int i;
    for(i = 0; i < N; i++){
        parent[i] = i;
    }
    for(i = 0; i < Q; i++){
        char command;
        int x, y;
        cin >> command >> x >> y;
        if(command == 'q'){
            if(x == y){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else if(command == 'c'){
            
        }
    }
}