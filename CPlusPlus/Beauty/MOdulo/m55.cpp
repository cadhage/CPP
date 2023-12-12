#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
ll CountBits(string n){
	ll count=0,un=0;
	for(char c:n){
		if(c=='1'){
			count++;
		}
	}
//	cout<<n<<" ";
	return count;
}
int main() 
{ 
    int tt;cin>>tt;
    ll sum=0;
    while(tt--){
    	ll s;string n;cin>>s>>n;
		cout<<CountBits(n)<<'\n';
	}
    return 0;
} 

