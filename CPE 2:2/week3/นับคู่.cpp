#include<cstdio>
#include<vector>

using namespace std;
vector<long long> item;

int main(){
    long long a, b, n;
    long long i, j;
    scanf("%lld %lld %lld",&n,&a,&b);
    //cout << n << " is N. " << a << " - " << b << "\n";
    long long cost;
    for(i = 0; i < n; i++){
        scanf("%lld",&cost);
        //cout << i << " is i.\n";
        item.push_back(cost);
    }

    vector<long long>::iterator it, l, u;
    sort(item.begin(),item.end());
    long long count = 0;
    for(it = item.begin(); it != item.end(); it++){
        long long upper = b - *it;
        long long lower = a - *it;
        u = upper_bound(it+1,item.end(),upper);
        l = lower_bound(it+1,item.end(),lower);
        long long dis = distance(l,u);
    
        count += dis;

    }

    printf("%lld",count);
}