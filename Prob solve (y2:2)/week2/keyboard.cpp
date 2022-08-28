#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    string s;
    stack<char> s1;
    int i;
    while(getline(cin, s)){
        int len = s.length();
        for(i = len-1; i > -1; i--){
            if(s[i] != '['){
                s1.push(s[i]);
            }else{
                if(s1.size() != 0){
                    char tmp = s1.top();
                    while(tmp != ']' && tmp != '['){
                        if(s1.size() == 0){
                            break;
                        }
                        cout << tmp;
                        s1.pop();
                        if(s1.size() != 0){
                            tmp = s1.top();
                        }
                    }
                }
            }
        }
        while(s1.size() != 0){
            if(s1.top() != '[' && s1.top() != ']'){
                cout << s1.top();
            }
            s1.pop();
        }
        cout << endl;
    }
}