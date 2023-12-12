#include <bits/stdc++.h>
using namespace std;
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
		long long n;
		cin>>n;
		int even=0,odd=0;
		for(int i=0;i<=n;i++)
			if(binomial(n,i)%2==0)
			even++;
			else odd++;
		cout<<even<<" "<<odd<<'\n';
	}
	return 0;
}
