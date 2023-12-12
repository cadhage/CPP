#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll CountBits(ll n){
	ll count=0;
	for(ll i=n;i!=0;i>>=1){
		if(1&i){
			count++;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(1000000);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a[x]++;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]==1)
			cout<<i<<" ";
	}
	return 0;
}
