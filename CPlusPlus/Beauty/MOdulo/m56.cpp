#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
int main() 
{ 
//	ll tt;cin>>tt;
//	while(tt--){
    ll n;cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
    	int x;cin>>x;
    	a.push_back({i,x});
	}
	sort(a.begin(),a.end(),[](auto i,auto j){
		return i.second<j.second;
	});
	for(int i=0;i<n;i++){
    	cout<<a[i].first<<' ';
	}
    return 0;
} 

