#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    cout << "\n";
    for(i = 0; i < n; i++){
        int s, f, m;
        vector< pair<int, int> > interval, ans;
        cin >> m;
        while(cin >> s >> f && (s != 0 || f != 0)){
            interval.push_back(make_pair(s, f));
        }
        sort(interval.begin(), interval.end());
        int j, now = 0, count = 0;
        pair<int, int> max;
        max.first = -1e9;
        max.second = -1e9;
        for(j = 0; j < interval.size(); j++){
            //cout << "  " << now << ": " << interval[j].first << ", " << interval[j].second << "\n";
            if(now >= m){
                //cout << " case1\n";
                break;
            }
            /*if(interval[j].first <= 0 && interval[j].second >= m){
                ans.push_back(interval[j]);
                count = 1;
                now = interval[j].second;
                break;
            }*/
            if(interval[j].first <= now && interval[j].second >= now){
                //cout << " case2\n";
                if(interval[j].second >= max.second){
                    //cout << " case21\n";
                    if(interval[j].second == max.second){
                        //cout << " case211\n";
                        if(max.first > interval[j].first){
                            //cout << " case2111\n";
                            max.second = interval[j].second;
                            max.first = interval[j].first;
                        }
                    }else{
                        //cout << " case212\n";
                        max.second = interval[j].second;
                        max.first = interval[j].first;
                    }
                }
                if(j == interval.size()-1){
                    //cout << " case22\n";
                    if(max.first <= now && max.second >= now){
                        //cout << " case221\n";
                        ans.push_back(max);
                        now = interval[j].second;
                        count++;
                    }
                    continue;
                }
            }else if(interval[j].first > now){
                //cout << " case3\n";
                ans.push_back(max);
                now = max.second;
                count++;
                if(max.first <= 0 && max.second >= m){
                    //cout << " case31\n";
                    //ans.push_back(interval[j]);
                    count = 1;
                    now = max.second;
                    break;
                }
                if(interval[j].first <= now && interval[j].second >= now){
                    //cout << " case32\n";
                    max.first = interval[j].first;
                    max.second = interval[j].second;
                }else{
                    //cout << " case33\n";
                    max.first = -1e9;
                    max.second = -1e9;
                }
            }
            
        }

        /*for(j = 0; j < ans.size(); j++){
            cout << "(" << ans[j].first << ", " << ans[j].second << ") ";
        }*/
        //cout << "\n";
        if(now >= m){
            cout << count << "\n";
            for(j = 0; j < count; j++){
                cout << ans[j].first << " " << ans[j].second << "\n";
            }
        }else{
            cout << 0 << "\n";
        }
        //cout << "\n";
    }
}