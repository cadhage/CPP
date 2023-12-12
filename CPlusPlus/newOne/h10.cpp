#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll max_so_far = INT_MIN, max_ending_here =0; 
    for (ll i = 0; i <n; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
	int mx=max(0ll,max_so_far);
	int cnt=0;
	max_so_far=INT_MIN,max_ending_here=0;
	for(int i=0;i<n;i++){
		max_ending_here=max_ending_here+a[i];
		if(max_ending_here==mx)
			cnt++;
		if(max_ending_here<0){
			max_ending_here=0;
		}
	} 
	cout<<mx<<" "<<cnt<<'\n';	
	return 0;
}
