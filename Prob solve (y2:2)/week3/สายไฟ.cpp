//#include<iostream>
//#include<vector>
//#include<math.h>
#include "stdc++.h"

using namespace std;

long n;

long long find_median(vector<long long> l){
    vector<long long>::iterator it1, it2;
    sort(l.begin(), l.end());
    if(n%2 != 0){
        return l[n/2];
    }
    return (l[n/2 - 1]+l[n/2])/2.0;
}

int main(){
    cin >> n;
    vector<long long> X, Y;
    vector<long long>::iterator it;
    long long x, y, i;

    for(i = 0; i < n; i++){
        cin >> x >> y;

        X.push_back(x + y);
        Y.push_back(y - x);
    }

    /*for(it = X.begin(); it != X.end(); it++){
        cout << *it << " ";
    }*/

    //cout << "\n";

    /*for(it = Y.begin(); it != Y.end(); it++){
        cout << *it << " ";
    }*/

    //cout << "\n";

    long long med_x = find_median(X);
    long long med_y = find_median(Y);

    //cout << med_x << " " << med_y << "\n";

    long long sum = 0;

    for(i = 0; i < n; i++){
        sum += abs(med_x - X[i]);
        //cout << sum << "\n";
    }

    for(i = 0; i < n; i++){
        sum += abs(med_y - Y[i]);
        //cout << sum << "\n";
    }
    

    cout << sum;
}