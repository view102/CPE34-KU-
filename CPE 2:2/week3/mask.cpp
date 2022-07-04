#include<iostream>
#include<list>

using namespace std;

int n;

int find_winner(long a, long pa, long b, long pb){
    if(a>b){
        return pa;
    }else{
        return pb;
    }
}

int find_loser(long a, long pa, long b, long pb){
    if(a>b){
        return pb;
    }else{
        return pa;
    }
}

int main(){
    cin >> n;
    int i, j;
    long skill;
    long player[(4*n)+1];
    long group[4][2];
    list<int> ans;
    int pos = 1, no;
    long max = -1;

    for(i = 0; i < 4; i++){
        for(j = 0; j < n; j++){
            cin >> skill;
            if(max < skill){
                max = skill;
                no = pos;
            }
            player[pos] = skill;
            pos++;
        }
        group[i][0] = no;
        group[i][1] = max;

        max = -1;
    }

    /*for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            cout << group[i][j] << " ";
        }
        cout << "\n";
    }*/

    int fourth = find_loser(group[2][1],group[2][0],group[3][1],group[3][0]);
    int third = find_loser(group[0][1],group[0][0],group[1][1],group[1][0]);
    int winB = find_winner(group[2][1],group[2][0],group[3][1],group[3][0]);
    int winA = find_winner(group[0][1],group[0][0],group[1][1],group[1][0]);
    int second = find_loser(player[winA],winA,player[winB],winB);
    int first = find_winner(player[winA],winA,player[winB],winB);

    ans.push_front(fourth);
    ans.push_front(third);
    ans.push_front(second);
    ans.push_front(first);


    list<int>::iterator it;
    for(it = ans.begin(); it != ans.end(); it++){
        if(it == ans.begin()){
            cout << *it;
            continue;
        }
        cout << " " << *it;
    }
    
}