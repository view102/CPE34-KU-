#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i, sum = 0;
    for(i = 0; i < n; i++){
        int cost;
        cin >> cost;
        if(cost > 0){
            sum = sum + cost;
        }
    }
    cout << sum;
}