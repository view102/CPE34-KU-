#include<iostream>
#include<list>
#include<string>

using namespace std;

list<char> demo;
list<char>::iterator its;
int main(){
    string g;
    while(getline(cin,g)){
        its = demo.begin();
        for (int i=0;i<g.size();i++){
            if (g[i] == '['){
                its = demo.begin();
            }else if(g[i] == ']'){
                its = demo.end();
            }else if (g[i] != ']' && g[i] != '['){
                demo.insert(its,g[i]);
            }
        }
        for (its = demo.begin();its!=demo.end();its++){
            cout << *its  ;
        }
        demo.clear();
        cout << '\n';
    }
}