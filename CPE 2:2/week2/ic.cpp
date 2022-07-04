#include<iostream>
#include<list>

using namespace std;

int main(){
    int commands, i;
    cin >> commands;

    list<int> l1;

    for(i = 0; i < commands; i++){
        string c;
        int n;
        cin >> c;
        if(c == string("ri") || c == string("li")){
            cin >> n;
        }
        
        if (c == string("lr") || c == string("rr")){
            if(l1.empty()){
                continue;
            }
        }
        if(c == string("ri")){
            l1.push_back(n);
        }else if(c == string("li")){
            l1.push_front(n);
        }else if(c == string("lr")){
            list<int>::iterator tmp = l1.begin();
            //cout << *tmp << " is tmp" << endl;
            l1.pop_front();
            l1.push_back(*tmp);
        }else{
            list<int>::iterator tmp = l1.end();
            tmp--;
            //cout << *tmp << " is tmp" << endl;
            l1.pop_back();
            l1.push_front(*tmp);
        }
    }

    list<int>::iterator it;
    for(it = l1.begin(); it != l1.end(); it++){
        cout << *it << endl;
    }
}