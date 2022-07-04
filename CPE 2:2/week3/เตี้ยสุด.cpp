#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, q;

long q1(int index, int s[],vector<int> v){
    int i;
    //vector<int>::iterator vit;
    //vector<int>::iterator min = min_element(v.begin(),v.begin()+index);
    return *(v.begin()+index-1);
}


int q2(int h, int s[], vector<int> v){
    int i;
    //sort(v.begin(),v.end());
    int vit;
    vit = lower_bound(v.begin(),v.end(),h) - v.begin();

    return vit;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, h;
    cin >> n >> q;
    int student[n+1];
    vector<int> student_q2;
    vector<int> v;
    int min = 1000000000;

    for(i = 1; i <= n; i++){
        //cout << i << "\n";
        cin >> student[i];
        //v.push_back(student[i]);
        if(min > student[i]){
            min = student[i];
        }
        v.push_back(min);
        student_q2.push_back(min);
    }
    vector<int>::iterator vit;
    int t, k;
    sort(student_q2.begin(),student_q2.end());
    for(i = 0; i < q; i++){
        cin >> t;
        cin >> k;
        if(t == 1){
            cout << *(v.begin()+k-1);
        }else{
            cout << n-(lower_bound(student_q2.begin(),student_q2.end(),k) - student_q2.begin());
        }
        cout << "\n";
    }
}