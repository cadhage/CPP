#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	n++;
	vector<string> a(n);
	vector<string> b(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(char c:s)
			a[i]+=(c=='*'?'a':c);
		for(char c:s)
			b[i]+=(c=='*'?'z':c);
	}
	string me=a[n-1];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int mn=n,mx=-1;
	for(int i=0;i<n;i++){
		if(a[i]==me)
			mx=max(mx,i);
		if(b[i]==me)
			mn=min(mn,i);
	}
	for(int i=mn;i<=mx;i++){
		if(i>mn)
			cout<<' ';
		cout<<i+1;
	}
	cout<<'\n';
	return 0;
}
