#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int total=0;
	total=(n+1)*(n+2)/2;
	for(int i=0;i<n;i++)
		total-=a[i];
	cout<<total<<'\n';
	return 0;
}
