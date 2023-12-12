#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solver(ll n,ll d){
	if(n==0||d==0)
		return;
	if(d%n==0)
	{
		cout<<"1/"+d/n;
		return;
	}
	if(n%d==0)
	{
		cout<<n/d;
		return;
	}
	if(n>d){
		cout<<n/d<<" + ";
		solver(n%d,d);
		return;
	}
	ll nr=d/n+1;
	cout<<"1/"<<nr<<" + ";
	solver(n*nr-d,d*nr);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,d;cin>>n>>d;
	solver(n,d);
	return 0;
}
