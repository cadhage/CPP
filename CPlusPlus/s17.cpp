#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll solver(ll a,ll b,ll m){
	ll res=0;
	a=a%m;
	while(b>0){
		if(b%2==1){
			res=(res+a)%m;
		}
		a=(a*2)%m;
		b=b/2;
	}
	return res%m;
}
ll multiply(ll a, ll b, ll mod) 
{ 
   return ((a % mod) * (b % mod)) % mod; 
} 
int main() 
{ 
   ll a = 9223372036854775807, b = 9223372036854775807; 
   cout << solver(a, b, 100000000000); 
   return 0; 
} 
