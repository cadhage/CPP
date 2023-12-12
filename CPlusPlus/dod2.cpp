#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
ll phi(ll N){
	ll result=N;
    for(ll p=2;p*p<=N;p++)
    {
        if(N%p==0)
        {
            while(N%p==0)
				N/=p;
			result*=(1.0-(1.0/(double)p));
        }
    }
    if(N>1){
    	result*=(1.0-(1.0)/(double)N);
	}
    return (result);
}
main()
{
 //   GeneratePrimes();
    ll n,k;cin>>n;
	ll ans=1;
	for(ll i=2;i<=n;i++){
		if(n%i==0)
		ans*=phi(i);
	}
	 cout<<ans;
    return 0;
}
