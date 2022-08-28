#include<iostream>
#include<utility>
#include<vector>

using namespace std;

void f(vector<int> &v){
    v[0] = 99;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    cout << v[0] << "\n";
    f(v);
    cout << v[0];
}