#include<iostream>
#include<vector>

using namespace std;
int n, m;

int main(){
    cin >> n >> m;
    int i, virus = 0;
    vector<int> data;
    for(i = 0; i < n; i++){
        int x;
        cin >> x;
        data.push_back(x);
    }
    for(i = 0; i < m; i++){
        int c;
        cin >> c;
        if(c == 1){
            virus = 0;
        }else if(c == 2){
            virus = (virus+1)%data.size();
        }else if(c == 3){
            int y;
            cin >> y;
            data.insert(data.begin()+virus, y);
            virus = (virus+1)%data.size();
        }else{
            int y;
            cin >> y;
            data.insert(data.begin()+virus+1, y);
        }
    }
    for(i = 0; i < data.size(); i++){
        cout << data[i] << "\n";
    }
}