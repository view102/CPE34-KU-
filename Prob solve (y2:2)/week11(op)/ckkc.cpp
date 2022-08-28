#include<iostream>

using namespace std;

int main(){
    int year;
    cin >> year;
    int y;
    int check = 2;
    while(cin >> y && y){
        //cout << check << "\n";
        if(check == 2){
            check = 1;
        }else{
            check = 2;
        }
    }
    if(check == 2){
        if(year%2 == 0){
            cout << "K";
        }else{
            cout << "C";
        }
    }else{
        if(year%2 == 0){
            cout << "C";
        }else{
            cout << "K";
        }
    }
}