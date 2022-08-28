#include<iostream>
#include<list>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1;
    int i;
    int c = 1;

    list<int> commands;

    while(c != 0){
        cin >> c;
        commands.push_back(c);
    }

    list<int>::iterator itc = commands.begin();
    n = *itc;

    while(n != 0){
        list<int> dummy, l1;

        for(i = 1; i <= n; i++){
            dummy.push_back(i);
        }
        while(dummy.size() > 1){
            list<int>::iterator tmp = dummy.begin();
            int data = *tmp;
            dummy.pop_front();
            l1.push_back(data);
            tmp = dummy.begin();
            dummy.push_back(*tmp);
            dummy.pop_front();
        }

        cout << "Discarded cards:";

        list<int>::iterator it;
        for(it = l1.begin(); it != l1.end(); it++){
            if(it == l1.begin()){
                cout << " " << *it;
            }else{
                cout << ", " << *it;
            }
        }

        cout << "\n";

        cout << "Remaining card: " << *(dummy.begin());

        advance(itc,1);
        n = *itc;

        if(n != 0){
            cout << "\n";
        }
    }

    cout << "\n";
    return 0;
}
