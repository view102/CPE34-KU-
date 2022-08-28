#include<iostream>
#include<cmath>

using namespace std;

int isprime(long long x) {

	if (x == 0 || x == 1 || (x % 2 == 0 && x > 2)) {
		return 0;
	}

	else {
		for (long long i=3; i <= (long long)sqrt(x)+1; i++) {
			if (x % i == 0) {
				return 0;
			}
		}
		return 1;
	}
}

int main(){
    int l, r;
    cin >> l >> r;
    int i, count = 0;
    for(i = l; i <= r; i++){
        if(isprime(i)){
            if(isprime(i+2)){
                count++;
                i++;
            }else{
                //i = i + 1;
            }
        }
    }
    cout << count;
}