#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n = -1;
    int i;
    while(n != 0){
        cin >> n;
        if(n == 0){
            break;
        }
        vector<int> weight;
        for(i = 0; i < n; i++){
            int data;
            cin >> data;
            weight.push_back(data);
        }
        sort(weight.begin(),weight.end());
        for(i = 0; i < n; i++){
            if(i == n-1){
                cout << weight[i];
                continue;
            }
            cout << weight[i] << " ";
        }
        cout << "\n";
    }
}