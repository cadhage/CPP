#include <bits/stdc++.h>
using namespace std;
void solver(vector<int> a,int n){
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n_atm;cin>>n_atm;
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		int dist[n],s=a[k];
		for(int i=0;i<n;i++){
			dist[i]=abs(a[i]-s);
		}
		cout<<s<<" : ";
		for(auto it:dist){
			cout<<it<<' ';
		}
		cout<<'\n';
	}
	//solver(a,n_atm);
	return 0; 
}
