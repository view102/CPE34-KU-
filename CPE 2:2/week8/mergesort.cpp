#include<iostream>
#include<vector>

using namespace std;
int n;
//vector<int> inv;

void merge(vector<int> &v, int s, int m, int f){
    vector<int> left;
    vector<int> right;
    int nl = (m-s) + 1;
    int nr = (f-(m+1)) + 1;
    int l = 0, r = 0, index = s;
    int i, j;
    for(i = s; i <= m; i++){
        left.push_back(v[i]);
        //cout << v[i] << " ";
    }
    //cout << " is left\n";
    for(i = m+1; i <= f; i++){
        right.push_back(v[i]);
        //cout << v[i] << " ";
    }
    //cout << " is right\n";
    while(l < nl && r < nr){
        if(left[l] <= right[r]){
            v[index] = left[l];
            l++;
        }else{
            v[index] = right[r];
            r++;
        }
        index++;
    }
    while(l < nl){
        v[index] = left[l];
        l++;
        index++;
    }
    while(r < nr){
        v[index] = right[r];
        r++;
        index++;
    }
    /*
    for(i = 0; i < index; i++){
        cout << v[i] << " ";
    }
    cout << " is merged\n";
    */
}


void mergesort(vector<int> &v, int s, int f){
    //cout << s << " : " << f << " is range\n";
    if(s < f){
        int med = s + (f-s)/2;
        mergesort(v,s,med);
        mergesort(v,med+1,f);
        merge(v, s, med, f);
    }
}

int main(){
    cin >> n;
    int i;
    vector<int> inv;
    for(i = 0; i < n; i++){
        int data;
        cin >> data;
        inv.push_back(data);
    }
    mergesort(inv,0,n-1);
    for(i = 0; i < n; i++){
        cout << inv[i] << " ";
    }
}