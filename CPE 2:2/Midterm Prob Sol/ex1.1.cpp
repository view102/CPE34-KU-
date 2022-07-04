#include<iostream>
#include<vector>
#include<list>

using namespace std;

int n;

int main(){
    cin >> n;
    int i;
    list<int> food;
    int number_round[n];
    for(i = 0; i <= n; i++){
        number_round[i] = 0;
    }
    //vector<int> max;
    for(i = 1; i < n+1; i++){
        int tmp;
        cin >> tmp;
        if(tmp > i){
            int index = tmp - i;
            number_round[index]++;
        }else{
            int index = (tmp+n) - i;
            number_round[index]++;
        }
    }
    int max = -1e9;
    for(i = 0; i <= n; i++){
        if(number_round[i] > max){
            max = number_round[i];
        }
    }
    cout << max;
    return 0;
}