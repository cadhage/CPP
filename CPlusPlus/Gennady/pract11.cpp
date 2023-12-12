#include <bits/stdc++.h>
using namespace std;
int binomial(int n,int k){
	int res=1;
	if(k>n-k)
		k=n-k;
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;cin>>n>>k;
	int count=0;
	for(int i=0;i<n;i++){
		int c;cin>>c;
		if(c%2==0){
			count++;
		}
	}
	cout<<binomial(count,k);
	return 0;
}
