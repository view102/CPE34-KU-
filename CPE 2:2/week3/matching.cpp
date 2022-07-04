#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q, i;
    vector<int> item_list;

    cin >> n >> q;

    for(i = 0; i < n; i++){
        int cost;
        cin >> cost;
        item_list.push_back(cost);
    }

    vector<int> cus_list;
    for(i = 0; i < q; i++){
        int customer, ticket;
        cin >> customer >> ticket;
        cus_list.push_back(item_list[customer-1] + ticket);
    }

    vector<int>::iterator it;
    for(i = 0; i < q; i++){
        //cout << cus_list[1] << "\n";
        it = upper_bound(item_list.begin(), item_list.end(), cus_list[i]);
        //cout << *(it-1);
        cout << (it-item_list.begin()) << "\n";
    }
}