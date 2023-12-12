#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll modularExponentiation(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
ll d, x, y;
void extendedEuclid(ll A,ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,c,M;cin>>a>>b>>c>>M;
	ll ans1=modularExponentiation(a,b,M);
	ll ans2=modInverse(c,M);
	cout<<(((ans1%M)*(ans2%M))%M);
	return 0;
}
