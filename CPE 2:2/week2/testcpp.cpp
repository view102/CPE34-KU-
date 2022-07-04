#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> l1;

    l1.push_back(6);
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(3);

    sort(l1.begin(),l1.end());
    
    vector<int>::iterator it;
    it = upper_bound(l1.begin(),l1.end(),3);
    
    cout << it - l1.begin();
    
}