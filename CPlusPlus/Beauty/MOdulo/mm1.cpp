/*yes there is a way
u have to calculate sum while you are inputting the numbers and in query u just directly access them using arrays
eg-> array is 1 2 3 4 5 
sum[0]=1;
sum[1]=3;
sum[2]=6;
sum[3]=10;
sum[4]=15;
now if you have to calculate sum between 2 and 4
we will do sum=sum[3]-sum[0]
and to calculate floor value we divide it by r-l+1
you will get the answer
hpoe u get it*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll n,q;cin>>n>>q;
	vector<ll> a(n);
	vector<ll> sumArr(n,0);
	ll sum=0;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		a[i]=x;
		if(i!=0)
			sumArr[i]=sumArr[i-1]+x;
		else sumArr[i]=x;
	}
//	for(int it:sumArr){
//		cout<<it<<' ';
//	}
	for(ll i=0;i<q;i++){
		ll l,r;cin>>l>>r;
		ll res=(sumArr[r-1]-sumArr[l-2])/(r-l+1);
		cout<<res<<'\n';
	}
	return 0;
}

