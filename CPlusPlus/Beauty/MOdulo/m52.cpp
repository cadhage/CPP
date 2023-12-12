#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool CountSucc(int n){
	ll count=0;
	vector<int> a(10000,false);
	int j=0;
	for(ll i=n;i!=0;i>>=1){
	    if(1&i)
	        a[j++]=true;
	   else a[j++]=false;
	}
	for(int i=1;i<a.size();i++){
	    if(a[i-1]==a[i])
	        return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q;cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(q--){
		int l,r,c=0;cin>>l>>r;
		for(int i=l-1;i<r;i++){
			if(!CountSucc(a[i]))
				c++;
		}
		cout<<c<<'\n';
	}
	return 0;
}
