#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(12);
    v.push_back(15);
    
    vector<int>::iterator it;

    it = upper_bound(v.begin(), v.end(), 6);

    cout << *(it-1);

}