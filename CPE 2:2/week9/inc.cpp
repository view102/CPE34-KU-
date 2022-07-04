#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

void find_seq(vector<int> &ans, int index, int opt[], int data[]){
    int i, max = 0, pos;
    for(i = 0; i <= index; i++){
        if(data[i] < data[index]){
            if(max < opt[i] + 1){
                max = opt[i] + 1;
                pos = i;
            }
        }
    }
    if(max > 1){
        ans.push_back(data[index]);
        find_seq(ans, pos, opt, data);
    }else{
        ans.push_back(data[index]);
    }
}

int main(){
    cin >> n;
    int i, j, index_ans, maxans = -1e9;
    int data[n];
    int opt[n];
    for(i = 0; i < n; i++){
        cin >> data[i];
        opt[i] = 0;
    }
    opt[0] = 1;
    for(i = 1; i < n; i++){
        int max = 0;
        for(j = 0; j < i; j++){
            if(data[j] < data[i]){
                if(opt[j] + 1 > max){
                    max = opt[j] + 1;
                }
            }
        }
        if(max > 1){
            opt[i] = max;
        }else{
            opt[i] = 1;
        }
        if(opt[i] > maxans){
            maxans = opt[i];
            index_ans = i;
        }
    }
    /*
    for(i = 0; i < n; i++){
        cout << opt[i] << " ";
    }
    cout << "\n" << maxans << " at opt[" << index_ans << "]\n";
    */
    vector<int> ans;
    find_seq(ans, index_ans, opt, data);
    reverse(ans.begin(), ans.end());
    cout << maxans << "\n";
    for(i = 0; i < ans.size(); i++){
        if(i == ans.size()-1){
            cout << ans[i];
            continue;
        }
        cout << ans[i] << " ";
    }
}