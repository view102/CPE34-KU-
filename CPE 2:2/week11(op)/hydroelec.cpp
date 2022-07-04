#include<iostream>

using namespace std;
int n;

int main(){
    cin >> n;
    int i, sum = 0;
    int water[n+1];
    water[0] = 0;
    for(i = 1; i <= n; i++){
        cin >> water[i];
        if(water[i] + 10 < water[i-1]){
            if((water[i-1]-water[i])*10 <= 700){
                sum += (water[i-1]-water[i])*10;
                //cout << sum << " is sum\n";
            }
        }
    }
    cout << sum;
}