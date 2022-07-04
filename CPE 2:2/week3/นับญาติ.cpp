#include<iostream>

using namespace std;

int n;

int check(int a, int b, int t[]){
    int k1 = a;
    int k2 = b;
    int r1, r2;
    while(1){
        if(k1 == b){
            r1 = 1;
            break;
        }
        if(k1 == t[k1]){
            r1 = 0;
            break;
        }
        k1 = t[k1];
    }
    while(1){
        if(k2 == a){
            r2 = 1;
            break;
        }
        if(k2 == t[k2]){
            r2 = 0;
            break;
        }
        k2 = t[k2];
    }
    if(r1 == 1){
        return b;
    }else if(r2 == 1){
        return a;
    }else{
        return -1;
    }
}

int main(){
    int m, i;
    cin >> n >> m; 
    int tree[n+1];
    tree[1] = 1;
    for(i = 2; i <= n; i++){
        cin >> tree[i];
    }
    /*for(i = 1; i <= n; i++){
        cout << tree[i] << " ";
    }*/

    cout << "\n";

    int a, b;
    for(i = 0; i < m; i++){
        cin >> a >> b;
        cout << check(a,b,tree) << "\n";
    }
}