#include<iostream>
#include<vector>
#include<numeric>

using namespace std;
int n;
int patient[1030];

int main(){
    cin >> n;
    int i, j, sum = 0;
    for(i = 0; i < n; i++){
        sum -= patient[i];
        int l;
        cin >> l;
        for(j = 0; j < l; j++){
            int a, b;
            cin >> a >> b;
            patient[i+b] += a;
            sum += a;
        }
        cout << sum << "\n";
    }
    /*for(i = 0; i < 1030; i++){
        if(patient[i] != 0){
            cout << patient[i] << " ";
        }
    }*/
}