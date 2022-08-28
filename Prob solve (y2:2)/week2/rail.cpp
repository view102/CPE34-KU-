#include<iostream>
#include<stack>
#include<list>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int n = -1;

    while(n != 0){
        cin >> n;
        if(n == 0){
            break;
        }
        list<int> l1;
        int t[10000];
        stack<int> s;
        list<int>::iterator it;

        //cout << "\n";

        while(1){
            cin >> t[0];
            if (t[0] == 0){
                break;
            }
            for(i = 1; i < n; i++){
                cin >> t[i];
            }
            //cout << "t = " << t << "\n";

            for(i = 0; i < n; i++){
                l1.push_back(t[i]);
            }

            it = l1.begin();
            //cout << *it << "\n";

            for(i = 1; i <= n; i++){
                s.push(i);
                //cout << *it << " && " << s.top() << "\n";
                if(i == *it && it != l1.end()){
                    s.pop();
                    it++;
                    //cout << *it << " // " << s.top() << "\n";
                    if (it != l1.end() && s.size() != 0){
                        while(s.top() == *it){
                            s.pop();
                            it++;
                            if(s.size() == 0){
                                break;
                            }
                        }
                    }
                }
            }

            if(s.size() == 0){
                cout << "Yes" << "\n";
            }else{
                cout << "No" << "\n";
            }

            l1.clear();
            while(s.size() != 0){
                s.pop();
            }
        }

        
        cout << "\n";
    }
}