#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
ll CountBits(ll n){
	ll count=0,un=0;
	for(ll i=n;i!=0;i>>=1){
	    count++;
	}
	return count;
}
int main() 
{ 
    int tt;cin>>tt;
    ll sum=0;
    while(tt--){
    	ll s;cin>>s;
    //	ll sum=0;
    	ll sum=CountBits(s);
		cout<<(2<<(sum-1))<<'\n';
	}
    return 0;
} 

