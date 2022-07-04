#include<iostream>
#include<cmath>

using namespace std;
int n;

int main(){
    cin >> n;
    int i, j;
    for(i = 0; i < n; i++){
        string s;
        cin >> s;
        //cout << s.size() << " is s\n"; 
        int ssize = s.size();
        int left = 'A';
        int right = 'A';
        int med = 13;
        int number_ap = 26;
        int sum = 0;
        for(j = 0; j < ssize; j++){
            int first, second;
            cout << char(left) << "(" << left << ") :";
            cout << char(right) << "(" << right << ") :";
            cout << s[j] << "(" << int(s[j]) << ") = ";
            if(abs(int(s[j]) - left) > 13){
                if(left < s[j]){
                    first = left+26-int(s[j]);
                }else{
                    first = int(s[j])+26-left;
                }
            }else{
                first = abs(left-int(s[j]));
            }
            if(abs(int(s[j]) - right) > 13){
                if(right < s[j]){
                    second = right+26-int(s[j]);
                }else{
                    second = int(s[j])+26-right;
                }
            }else{
                second = abs(right-int(s[j]));
            }
            sum += min(first,second);
            cout << min(first,second) << "\n";
            if(first < second){
                left = s[j];
            }else{
                right = s[j];
            }
        }
        cout << sum << "\n";
    }
}