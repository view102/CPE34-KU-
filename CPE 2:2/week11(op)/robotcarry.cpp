#include<iostream>
#include<cmath>

using namespace std;
int n, m;

int main(){
    cin >> n >> m;
    int i, j;
    int robot[n+1];
    int rest[n+1];
    for(i = 1; i <= n; i++){
        cin >> robot[i];
        rest[i] = 0;
    }
    int sum = 0;
    for(i = 0; i < m; i++){
        int pos;
        cin >> pos;
        int min = 1e9;
        int robotmin;
        for(j = 1; j <= n; j++){
            if(rest[j] == 0){
                int dis = abs(pos-robot[j]);
                if(min > dis){
                    min = dis;
                    robotmin = j;
                }
            }else{
                rest[j] = 0;
            }
        }
        rest[robotmin] = 1;
        sum += min;
    }
    cout << sum;
}