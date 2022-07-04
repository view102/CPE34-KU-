#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n;

bool sortSecPairs(const pair<int, int> &x, const pair<int, int> &y){
    return x.second < y.second;
}

int main(){
    cin >> n;
    int i;
    vector< pair<int, int> > interval;
    for(i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        interval.push_back(make_pair(x, y));
    }

    sort(interval.begin(), interval.end(), sortSecPairs);

    int index = 0;
    int count = 0;

    for(i = 0; i < n; i++){
        if(index <= interval[i].first){
            count += 1;
            index = interval[i].second;
        }
    }

    cout << count;
    return 0;
}