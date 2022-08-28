#include<iostream>
#include<list>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int commands, i;
    cin >> commands;

    list<int> l1;

    for(i = 0; i < commands; i++){
        char c;
        int n, j;

        cin >> c;
        cin >> n;

        //cout << c << " : " << n << "\n";
        list<int>::iterator index = l1.begin();

        if(c == 'I'){
            l1.push_front(n);
        }else{
            if(n <= l1.size()){
                for(j = 1; j < n; j++){
                index++;
                }
                //cout << *index << "\n";
                l1.erase(index);
                index = l1.begin();
            }
        }
        //cout << i << "\n";
        /*
        list<int>::iterator it;
        for(it = l1.begin(); it != l1.end(); it++){
            cout << *it << " ";
        }
        cout << "\n";
        */
    }

    list<int>::iterator it;
    for(it = l1.begin(); it != l1.end(); it++){
        cout << *it << "\n";
    }
}
