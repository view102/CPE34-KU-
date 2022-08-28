#include<iostream>
#include<string>

using namespace std;

int main(){
    string c , ans = "";
    int i;
    char status[4] = {'N','E','S','W'};
    int j = 0;
    
    //ans.clear();

    cin >> c;

    int len = c.length();
    
    //cout << len;

    for(i = 0; i < len; i++){
        //cout << "ANS : " << ans << "\n";
        char command = c[i];
        if(command == 'Z'){
            ans.push_back('Z');
            j = 0;
            continue;
        }
        while(command != status[j]){
            ans.push_back('R');
            j = (j+1)%4;
        }
        ans.push_back('F');
    }

    cout << ans;
}