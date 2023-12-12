#include <bits/stdc++.h>
using namespace std;
vector<int> prime(1000,true);
void solver(int n){
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
}
int main(){
	solver(1000);
	for(int i=0;i<1000;i++){
		if(prime[i])
			cout<<i<<'\n';
	}
	return 0;
}
