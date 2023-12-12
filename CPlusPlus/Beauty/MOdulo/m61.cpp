#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
int main() 
{ 
	ll tt;cin>>tt;
	while(tt--){
    ll n,x;cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a.begin(),a.end(),[](auto a,auto b){
		return a>b;
	});
	int sum1=0,sum2=0;
	for(int i=0;i<n-x;i++){
    	sum1+=a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n-x;i++){
    	sum2+=a[i];
	}
	cout<<abs(sum1-sum2)<<'\n';
	}
    return 0;
} 

