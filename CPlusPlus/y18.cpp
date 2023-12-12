#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		for(int i=0;i<n;i++)
			a[i]=a[i]/x;
	}
	for(auto it:a)
		cout<<it<<' ';
	return 0;
}
