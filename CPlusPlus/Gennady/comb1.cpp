#include <bits/stdc++.h>
using namespace std;
int binomial(int n,int k){
	int res=1;
	if(k>(n-k)){
		k=n-k;
	}
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
void pascal(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<binomial(i,j)<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	pascal(7);
	return 0;
}
