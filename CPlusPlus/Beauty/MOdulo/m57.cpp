#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
int main() 
{ 
//	ll tt;cin>>tt;
//	while(tt--){
	int n,m;cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<pair<int,int>> h(m);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		h[i]=make_pair(x,y);
	}
	for(int k=0;k<n;k++){
		int sum=0;
		for(int i=0;i<m;i++){
			if(h[i].first<=a[k])
				sum+=h[i].second;
		}
		cout<<sum<<'\n';
	}
    return 0;
} 

