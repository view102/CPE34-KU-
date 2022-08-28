#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
int n;

void find_seq(vector<int> &ans, int index, int opt[], pair< int, int > interval[], int price[]){
    int i, max = 0, pos;
    //cout << index << "\n";
    if(index == 0){
        return;
    }
    for(i = 0; i < index; i++){
        if(interval[i].second <= interval[index].first){
            if(max < opt[i] + price[index]){
                max = opt[i] + price[index];
                pos = i;
            }
        }
    }
    if(max < opt[index-1]){
        find_seq(ans,index-1,opt,interval,price);
    }else{
        ans.push_back(index);
        find_seq(ans, pos, opt, interval,price);
    }
}

int main(){
    cin >> n;
    int i, j, index_ans, maxans = 0;
    int price[n+1];
    int opt[n+1];
    pair<int, int> interval[n+1];
    for(i = 1; i <= n; i++){
        int s, t, w;
        cin >> s >> t >> w;
        interval[i] = make_pair(s,t);
        price[i] = w;
        opt[i] = 0;
    }
    /*for(i = 1; i <= n; i++){
        cout << "(" << interval[i].first << "," << interval[i].second << ")" << ": ";
        cout << price[i]; 
        cout << "\n";
    }*/
    opt[0] = 0; opt[1] = price[1];
    for(i = 2; i <= n; i++){
        int max = 0;
        for(j = 0; j < i; j++){
            if(interval[j].second <= interval[i].first){
                if(max < opt[j]+price[i]){
                    max = opt[j] + price[i];
                }
            }
        }
        /*if(max < price[i]){
            max = price[i];
        }*/
        if(max > opt[i-1]){
            opt[i] = max;
            if(maxans < opt[i]){
                maxans = opt[i];
                index_ans = i;
            }
        }else{
            opt[i] = opt[i-1];
            if(maxans < opt[i]){
                maxans = opt[i];
                index_ans = i;
            }
        }
        //cout << opt[i] << " " << max  << " " << opt[i-1] << "\n";
    }
    //cout << maxans << ": opt " << index_ans;
    /*for(i = 0; i <= n; i++){
        cout << opt[i] << " ";
    }*/
    //cout << "\n";
    vector<int> ans;
    find_seq(ans,index_ans,opt,interval,price);
    reverse(ans.begin(), ans.end());
    cout << maxans << "\n" << ans.size() << "\n";
    for(i = 0; i < ans.size(); i++){
        if(i == ans.size()-1){
            cout << ans[i];
            continue;
        }
        cout << ans[i] << " ";
    }
}