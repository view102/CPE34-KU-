#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;
int m;
int ans[500010], pos[500010];
vector<int> v;

int main(){
    cin >> m;
    int i, x, j;
    int max_len = -1, count = 0;
    ans[0] = 0;
    pos[0] = 0;
    v.push_back(0);
    for(i = 1; i <= m; i++){
        cin >> x;
        v.push_back(x);
        ans[i] = 0;
        pos[i] = 0;
    }
    for(i = 1; i <= m; i++){
        //cout << v[i] << " : \n";
        if(v[i] > v[i-1]){
            for(j = v[i-1] + 1; j <= v[i]; j++){
                pos[j] = i;
            }
        }
        if(v[i] < v[i-1]){
            
            for(j = v[i] + 1; j <= v[i-1]; j++){
                //cout << i - pos[j] << " is len\n";
                if(ans[i - pos[j]] == 0){
                    count++;
                }
                if(max_len < i-pos[j]){
                    max_len = i-pos[j];
                }
                ans[i - pos[j]]++;
            }
        }
        if(i == m){
            int next = i + 1;
            v[next] = 0;
            if(v[next] > v[i]){
                for(j = v[i] + 1; j <= v[next]; j++){
                    pos[j] = i;
                }
            }
            if(v[next] < v[i]){
                for(j = v[next] + 1; j <= v[i]; j++){
                    //cout << i - pos[j] << " is len\n";
                    if(ans[next - pos[j]] == 0){
                        count++;
                    }
                    if(max_len < next-pos[j]){
                        max_len = next-pos[j];
                    }
                    ans[next - pos[j]]++;
                }
            }
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