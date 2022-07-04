#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int now = 0;

    string T;
    cin >> T;
    int size_T = T.size();
    int i, count = 0;
    for(i = 0; i < size_T; i++){
        if(s[now] == T[i]){
            now += 1;
            if(now >= s.size()){
                now = now%s.size();
                count += 1;
            }
        }
    }
    cout << count;
}