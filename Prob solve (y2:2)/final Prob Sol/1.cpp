#include<iostream>

using namespace std;
int n, s;

int main(){
    cin >> n >> s;
    int i, j;
    int data[20];
    for(i = 0; i < n; i++){
        cin >> data[(i+s)%20];
    }
    int num = 1;
    for(i = n; i < 20; i++){
        data[(i+s)%20] = num;
        num++;
    }
    /*for(i = 0; i < 20; i++){
        cout << data[i] << " ";
    }*/
    //cout << "\n";
    int ans[4][5];
    int index = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            ans[i][j] = data[index];
            index++;
        }
    }
    /*for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }*/
    for(j = 0; j < 5; j++){
        for(i = 0; i < 4; i++){
            cout << ans[i][j] << " ";
        }
    }
}