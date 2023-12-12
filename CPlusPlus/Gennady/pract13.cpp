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
	cout<<binomial(5+3,2);
	return 0;
}
