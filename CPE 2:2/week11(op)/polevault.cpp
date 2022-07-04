#include<iostream>

using namespace std;
int n, q;

int main(){
    cin >> n >> q;
    int i, j, k;
    string s;
    int data[n];
    for(i = 0; i < n; i++){
        cin >> data[i];
    }
    for(i = 0; i < q; i++){
        int l;
        cin >> l;
        int check = 0;
        for(j = 0; j < n; j++){
            int tmp = l;
            for(k = j; k < n; k++){
                tmp -= data[k];
                if(tmp == 0){
                    check = 1;
                }
            }
        }
        if(check == 1){
            //cout << "Y";
            s.push_back('Y');
        }else{
            //cout << "N";
            s.push_back('N');
        }
    }
    cout << s;
}