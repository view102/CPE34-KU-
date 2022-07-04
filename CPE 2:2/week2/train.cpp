#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
list<int> l1[100001];

void printl(list<int> const &list){
    copy(list.begin(), list.end(), ostream_iterator<int>(cout, "\n"));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i, j;
    int max = -1;
    cin >> N;

    char c;
    int from, to;
    list<int>::iterator it;

    for(i = 0; i < N; i++){
        cin >> c;
        cin >> from;
        cin >> to;

        if(max < to){
            max = to;
        }

        if(c == 'N'){
            l1[to].push_back(from);
        }else{
            /*for(it = l1[from].begin(); it != l1[from].end(); it++){
                l1[to].push_back(*it);
            }*/

            l1[to].splice(l1[to].end(), l1[from]);
            l1[from].clear();
        }

        //int size_l = sizeof(l1)/sizeof(l1[0]);

        //cout << size_l << " is size." << "\n";
    }

    int k;
    for(k = 1; k <= max; k++){
        /*for(it = l1[k].begin(); it != l1[k].end(); it++){
            cout << *it << "\n";
        }*/
        printl(l1[k]);
    }
    
    return 0;
}
