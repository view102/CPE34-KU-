#include<iostream>
#include<vector>
#include<list>

using namespace std;

int n;

int main(){
    cin >> n;
    int i;
    list<int> food;
    //vector<int> max;
    for(i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        food.push_back(tmp);
    }

    int max = -1e9;

    for(i = 0; i < n; i++){
        list<int>::iterator j;
        int count = 0;
        int index = 1;
        for(j = food.begin(); j != food.end(); j++){
            if(*j == index){
                count++;
            }
            index++;
        }
        if(max < count){
            max = count;
        }
        int tmp = food.front();
        food.pop_front();
        food.push_back(tmp);
    }
    
    cout << max;
    /*for(i = 0; i < n; i++){
        cout << food[i] << " ";
    }*/


    return 0;
}