#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int m;

int main(){
    cin >> m;
    int i, x, j;
    vector<int> v;
    int ans[100010];
    int max_l = -1, max_len = -1, count = 0;
    ans[0] = 0;
    for(i = 0; i < m; i++){
        cin >> x;
        v.push_back(x);
        if(x > max_l){
            max_l = x;
        }
        ans[i+1] = 0;
    }
    for(i = 0; i < max_l; i++){
        int l = 0;
        for(j = 0; j < v.size(); j++){
            if(v[j] != 0){
                v[j] = v[j] - 1;
                l = l + 1;
            }else{
                if(l != 0){
                    if(l > max_len){
                        max_len = l;
                    }
                    if(ans[l] == 0){
                        //cout << l << " is l first\n";
                        count++;
                    }
                    //cout << l << " is l\n";
                    ans[l] += 1;
                    l = 0;
                }
            }
        }
        if(l != 0){
            if(ans[l] == 0){
                count++;
            }
            if(l > max_len){
                max_len = l;
            }
            ans[l]++;
        }
    }
    cout << count << "\n";
    for(i = 1; i <= max_len; i++){
        if(ans[i] != 0){
            cout << i << " " << ans[i] << "\n";
        }
    }

    return 0;
}