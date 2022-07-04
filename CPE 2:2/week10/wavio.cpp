#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

int main(){
    while(cin >> n){
        int i, j, index_ans, maxans = -1e9;
        int data[n],data2[n];
        int lis[n];
        int lds[n];
        for(i = 0; i < n; i++){
            cin >> data[i];
            data2[n-1-i] = data[i];
            lis[i] = 0;
            lds[i] = 0;
        }
        lis[0] = 0;
        lds[0] = 0;
        for(i = 1; i < n; i++){
            int max = 0;
            int max2 = 0;
            for(j = 0; j < i; j++){
                if(data[j] < data[i]){
                    if(lis[j] + 1 > max){
                        max = lis[j] + 1;
                    }
                }
                if(data2[j] < data2[i]){
                    if(lds[j] + 1 > max2){
                        max2 = lds[j] + 1;
                    }
                }
            }
            if(max > 1){
                lis[i] = max;
            }else{
                lis[i] = 1;
            }
            if(max2 > 1){
                lds[i] = max2;
            }else{
                lds[i] = 1;
            }
        }
        /*
        for(i = 1; i < n; i++){
            int max = 0;
            for(j = 0; j < i; j++){
                if(data2[j] < data2[i]){
                    if(lds[j] + 1 > max){
                        max = lds[j] + 1;
                    }
                }
            }
            if(max > 1){
                lds[i] = max;
            }else{
                lds[i] = 1;
            }
        }
        */
        /*
        for(i = 0; i < n; i++){
            cout << lis[i] << " ";
        }
        cout << "\n";
        for(i = n-1; i >= 0; i--){
            cout << lds[i] << " ";
        }
        */
        int max_wav = -1e9;
        int lds_index = n-1;
        for(i = 0; i < n; i++){
            int ans;
            if(lis[i] == 1 || lds[lds_index] == 1 || lis[i] == 0 || lds[lds_index] == 0){
                ans = 1;
            }else{
                ans = lis[i] + lds[lds_index];
            }
            if(max_wav < ans){
                max_wav = ans;
            }
            lds_index--;
        }
        cout << max_wav << "\n";
    }
}