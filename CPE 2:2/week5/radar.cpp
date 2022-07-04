#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<math.h>
#include<cstdio>
//#include<bits/stdc++.h>

using namespace std;

int n, d;

int main(){
    //cin >> n >> d;
    int i;
    int round = 0;
    vector<int> ans;
    while(cin >> n >> d && n != 0){
        int error = 0;
        vector< pair<double, double> > island;
        for(i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            double s, f;
            if(y > d){
                error = 1;
            }
            //cout << " sqrt: " << sqrt(pow(d,2) - pow(y,2));
            s = x - sqrt(pow(d,2) - pow(y,2));
            f = x + sqrt(pow(d,2) - pow(y,2));
            //cout << " " << s << ", " << f << "\n";
            island.push_back(make_pair(s, f));
        }

        sort(island.begin(), island.end());
        
        double now = island[0].second;
        int count = 1;
        if(error){
            count = -1;
        }else{
            for(i = 1; i < n; i++){
                //cout << "  ";
                //cout << island[i].first << ", " << island[i].second << "\n";
                if(island[i].first > now){
                    now = island[i].second;
                    count += 1;
                }else if(island[i].first <= now){
                    if(now > island[i].second){
                        now = island[i].second;
                    }
                }
            }
        }
        //ans.push_back(count);
        round += 1;
        cout << "Case " << round << ": " << count << "\n";
        
        //cout << "\n";
    }

    /*for(i = 0; i < ans.size(); i++){
        cout << "Case " << i+1 << ": " << ans[i] << "\n"; 
    }*/
    //cout << "\n";
    return 0;
}
