#include <bits/stdc++.h>
using namespace std;
int solver(int n,int k){
	int res=1;
	if(k>n-k)
		k=n-k;
	for(int i=0;i<k;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
void printPascle(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"1/"<<i*solver(i-1,j-1)<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n=8,k=2;
	//solver(n,k);
	printPascle(7);
	return 0;
}
