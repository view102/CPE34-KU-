#include "probelib.h"
#include<iostream>

using namespace std;

void divide_conquer(int a, int b){
    cout << a << " " << b << "\n";
    if(a == b){
        probe_answer(a);
    }
    if(probe_check(a, (a+b)/2)){
        divide_conquer(a , (a+b)/2);
    }else{
        divide_conquer(((a+b)/2)+1, b);
    }
}

int main(){
    int n = probe_init();
    divide_conquer(0, n-1);
    return 0;
}