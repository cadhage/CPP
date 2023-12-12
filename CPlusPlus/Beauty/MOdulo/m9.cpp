#include <bits/stdc++.h>
using namespace std;
vector<int> factorize(int n) {
	int minPrime[n + 1];
	for (int i = 2; i * i <= n; ++i) {
	    if (minPrime[i] == 0) {         //If i is prime
	        for (int j = i * i; j <= n; j += i) {
	            if (minPrime[j] == 0) {
	                minPrime[j] = i;
	            }
	        }
	    }
	}
	for (int i = 2; i <= n; ++i) {
	    if (minPrime[i] == 0) {
	        minPrime[i] = i;
	    }
	}
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
int main(){
	vector<int> res=factorize(1000);
	for(int i:res){
		cout<<i<<" ";
	}
}
