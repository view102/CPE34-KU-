#include<iostream>
#include<list>

using namespace std;

int n;

int find(int pos, int l[]){
    while(1){
        if(pos == l[pos]){
            return pos;
        }
        pos = l[pos];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    list<int>::iterator it;
    cin >> n;

    int listindex[n+1];
    list<int> l1[n+1]; 

    for(i = 1; i <= n; i++){
        l1[i].push_back(i);
        listindex[i] = i;
    }

    int x, y;
    list<int>::iterator index;
    for(i = 1; i < n; i++){
        cin >> x >> y;

        int pos = find(y,listindex);
        for(index = l1[pos].begin(); index != l1[pos].end(); index++){
            if(*index == y){
                index++;
                break;
            }
        }
        l1[y].splice(index,l1[x]);
        l1[x].clear();
        listindex[x] = y;

    }

    for(i = 1; i <= n; i++){
        if(l1[i].size() != 0){
            for(it = l1[i].begin(); it != l1[i].end(); it++){
                if(it == l1[i].begin()){
                    cout << *it;
                }else{
                    cout << " " << *it;
                }
            }
        }
    }
    
}
