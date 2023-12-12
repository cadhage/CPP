#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,s;cin>>n>>s;
	vector<pair<int,int>> p;
	int mx=0;
	for(int i=0;i<n;i++){
		int t,d;cin>>t>>d;
		mx=max(t,mx);
		p.push_back({t,d});
	}
	
	vector<pair<int,int>> temp(mx,{0,0});
	int prev=0;
	for(int i=p[0].first;i<=mx;i++){	
		for(int k=0;k<n;){
			if(p[k].first>=i){
				k++;
			}
			else 
				a.push_back(i,p[k].second);
		}
	}
	return 0;
}

