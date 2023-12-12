#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	int n;cin>>n;
	vector<int> s(n);
	vector<int> e(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>e[i];
	}
	int mx=0;
	int root=0;
	for(int i=0;i<n;i++){
		if(mx<e[i]-s[i]){
			mx=e[i]-s[i];
			root=i;
		}
	}
	cout<<mx;
	return 0;
}
