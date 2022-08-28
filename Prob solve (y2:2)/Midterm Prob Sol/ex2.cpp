#include<iostream>
#include<vector>

using namespace std;

int k, n;

int main(){
    cin >> k >> n;
    vector<int> contact[k]; 
    int i;
    for(i = 0; i < k; i++){
        int c, p, w;
        cin >> c >> p >> w;
        contact[i].push_back(c);
        contact[i].push_back(p);
        contact[i].push_back(w);   
    }

    vector<int> item;
    for(i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        item.push_back(tmp);
    }

    int j;
    int min = 1e9;
    for(i = 0; i < k; i++){
        int limit = contact[i][2];
        int total_w = 0, count = 1;
        int cost;
        int over = 0;
        for(j = 0; j < n; j++){
            //cout << "  " << limit << " , " << total_w << "\n";
            if(item[j] > limit){
                over = 1;
                break;
            }
            if(total_w + item[j] > limit){
                count++;
                total_w = item[j];
                continue;
            }
            total_w += item[j];
        }
        //cout << " " << count << " : " << over << "\n";
        if(over == 1){
            cost = 0;
        }else{
            cost = contact[i][0] + (contact[i][1]*count);
            if(cost < min){
                min = cost;
            }
        }
        
    }
    cout << min;

    return 0;
}