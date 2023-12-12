#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void SieveofEratosthenes(int n){
	vector<bool> v(n,0);
	for(int i=2;i<n+2;i++){
		if(!v[i]){
			for(int j=i*i;j<n+2;j+=i){
				v[j]=true;
			}
			primes.push_back(i);
		}
	}
}
bool specialPrimeNumbers(int n,int k){
	SieveofEratosthenes(n);
	int count=0;
	for(int i=0;i<primes.size();i++){
		for(int j=0;j<i-1;j++){
			if(primes[j]+primes[j+1]+1==primes[i]){
				count++;
				break;
			}
		}
	}
	if(count==k)
		return true;
	return false;
}
int main(){
	int n = 27, k = 2; 
    if (specialPrimeNumbers(n, k)) 
        cout << "YES" << endl; 
    else
        cout << "NO" << endl; 
	return 0;
}
