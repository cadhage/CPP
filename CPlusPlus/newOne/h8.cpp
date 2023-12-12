#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
ll MOD=1e9+7;
int binomial(long long n,long long k){
	if(k>n-k){
		k=n-k;
	}
	long long res=1;
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		 n;cin>>n;
		cout<<binomial(pow(2,n),n)
	}
	return 0;
}
