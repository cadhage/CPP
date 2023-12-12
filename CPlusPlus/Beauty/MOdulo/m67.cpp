#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
int main() 
{ 
//	ll tt;cin>>tt;
//	while(tt--){
    ll n;cin>>n;
    vector<pair<string,int>> a;
    for(int i=0;i<n;i++){
    	int x;string s;cin>>s>>x;
    	a.push_back({s,x});
	}
	sort(a.begin(),a.end(),[](auto i,auto j){
		if(i.second==j.second){
			return i.first>j.first;
		}
		else return i.second<j.second;
	});
	cout<<a[0].first<<'\n';
    return 0;
} 

