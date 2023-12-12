#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<vector<int>> a(n,vector<int>(k));
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>a[i][j];
		}
	}
	vector<double> ans(k);
	double prob=1.0;
	for(int i=n-1;i>=0;i--){
		int cc=accumulate(a[i].begin(),a[i].end(),0);
		for(int j=0;j<k;j++){
			ans[j]+=prob*a[i][j]/(cc+!!i);
		}
		prob*=1.0/(cc+!!i);
	}
	cout<<fixed<<setprecision(17);
	for(int j=0;j<k;j++){
		if(j>0){
			cout<<" ";
		}
		cout<<ans[j];
	}
	cout<<'\n';
	return 0;
}
