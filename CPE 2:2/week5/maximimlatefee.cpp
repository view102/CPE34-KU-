#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
//#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    vector<pair<int, int> > job;
    for(i = 0; i < n; i++){
        int dead, dur;
        cin >> dead >> dur;
        job.push_back(make_pair(dead, dur));
    }
    int day = 0;
    sort(job.begin(), job.end());
    int max = -1;

    for(i = 0; i < n; i++){
        int x;
        day += job[i].second;
        if(day > job[i].first + 10){
            x = (day - job[i].first - 10)*1000;
        }else{
            x = 0;
        }
        if(x > max){
            max = x;
        }
    }

    /*for(i = 0; i < n; i++){
        cout << job[i].first << " : " << job[i].second << "\n";
    }*/

    cout << max;
    return 0;
}