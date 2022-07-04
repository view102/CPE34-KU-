#include<iostream>
#include<list>
#include<stack>
#include<string>
using namespace std;
stack<int> demo;
int keep[100000];

int main(){
    int m,s;
    while(1){
        cin >> m;
        if (m == 0){
            break;
        }
        while(1){
            cin >> keep[0];
            if (keep[0] == 0){
                cout << '\n';
                break;
            }
            for (int i=1;i<m;i++){
                cin >> keep[i];
            }
            s = 0;
            for (int i=1;i<=m;i++){
                demo.push(i);
                while(!demo.empty() && keep[s] == demo.top()){
                    demo.pop();
                    s = s+1;
                }        
            }
            if (demo.empty()){
                cout << "Yes" <<'\n';
            }else{
                cout << "No" <<'\n';
            }
            while(!demo.empty()){
                demo.pop();
            }
        }    
    }
}               