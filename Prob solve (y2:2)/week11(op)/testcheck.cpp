#include<iostream>

using namespace std;
int n, m;

int main(){
    cin >> n >> m;
    int count[n+1], maxscore[n+1], fail[n+1];
    int i;
    for(i = 1; i <= n; i++){
        count[i] = 0;
        maxscore[i] = -1e9;
    }
    for(i = 0; i < m; i++){
        int n_exam, score;
        cin >> n_exam >> score;
        if(count[n_exam] > 5){
            maxscore[n_exam] = 0;
        }else{
            count[n_exam]++;
            if(score > maxscore[n_exam]){
                maxscore[n_exam] = score;
            }
            if(count[n_exam] > 5){
                maxscore[n_exam] = 0;
            }
        }
    }
    int sum = 0;
    for(i = 1; i <= n; i++){
        if(maxscore[i] != -1e9){
            sum += maxscore[i];
        }
    }
    cout <<  sum;
}