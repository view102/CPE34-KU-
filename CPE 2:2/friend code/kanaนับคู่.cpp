#include<iostream>
#include<vector>
using namespace std;
vector<long long int> demo;
vector<long long int>::iterator its;

int main(){
    long long int N,A,B,k,count=0,v1,v2;
    scanf("%lld %lld %lld",&N,&A,&B);
    for(int i=0;i<N;i++){
        scanf("%lld",&k);
        demo.push_back(k);
    }
    
    sort(demo.begin(),demo.end());
    long long int k1,k2;
    for (its = demo.begin();its!=demo.end();its++){
        k1 = A - *its;
        k2 = B - *its;    
        vector<long long  int>::iterator v1 = upper_bound(its+1,demo.end(),k2);
        vector<long long  int>::iterator v2 = lower_bound(its+1,demo.end(),k1);
        printf("%d %d %d\n",v2-demo.begin(),v1-demo.begin(),*its);
        if (v1-v2 >0){
            count += (long long int)(v1-v2);
        }
    }
    cout << count;
}