#include <bits/stdc++.h>
using namespace std;
int mnele(vector<int> a,int t){
	int mx=a[t-1];
	for(int i=t;i<(a.size()+t);i++){
		if(i>(t-1) & & a[i%a.size()]<t && mx>a[i%a.size()])
				mx=a[i%a.size()];
	}
	return mx;
}
void solver(vector<int> a){
	int n=a.size();
	vector<int> x;
	for(int i=1;i<=n;i++){
			int mn=mnele(a,i);
			cout<<mn<<' ';
		}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solver(a);
	return 0;
}
