#include<iostream>
#include<list>

using namespace std;

typedef struct node{
    int start;
    int end;
}bridge_t;

int N;

int cal(float a, bridge_t b[]){
    int i;
    int count = 0;
    for(i = 0; i < N; i++){
        if(a > b[i].start && a < b[i].end){
            count++;
        }
    }
    return count;
}

int main(){
    int L, j;
    float i;
    int max = -1;
    cin >> L >> N;
    
    bridge_t b[N];

    for(j = 0; j < N; j++){
        int x, y;
        cin >> x >> y;
        //cout << j << "\n";
        b[j].start = x;
        b[j].end = y;
    }

    for(i = 0; i <= L; i = i + (0.5)){
        //cout << i << "\n";
        int num_under = cal(i,b);
        if(max < num_under){
            max = num_under;
        }

        //cout << "i is " << i << " and num_under is " << num_under << "\n";
    }

    cout << max;
}