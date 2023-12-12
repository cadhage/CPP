#include <bits/stdc++.h>
using namespace std;
int count=0;
void solver(vector<int> a){
	sort(a.begin(),a.end());
	pair<int,int> v[a.size()];
	v[0]=make_pair(a[0],0);
	for(int i=1;i<a.size();i++){
		if(a[i]>v[i-1].first){
			v[i]=make_pair(a[i],1);
		}
		if(a[i]<v[i-1].first){
			v[i]=make_pair(a[i],0);
		}
		else{
			v[i]=make_pair(a[i],0);
		}
	}
	for(auto it:v){
		cout<<it.first<<' '<<it.second<<'\n';
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
