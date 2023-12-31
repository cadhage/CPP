#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll  long long int
deque<ll> dq;
int a[INT_MAX],f[INT_MAX],trace[INT_MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	int n,k;cin>>n>>k;
	while(!dq.empty())
		dq.pop_back();
	cin>>a[0];f[0]=log(a[0]);
	trace[0]=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(!dq.front() && i-dq.front()>k)
			dq.pop_front();
		while(!dq.empty() && f[i]<=f[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	ll ans=1;
	for(int i=n-1;i>=0;i=trace[i]){
		ans*=(ll)a[i];
		ans%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}
/* 7725229
#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>
 
using namespace std;
 
#define lp1(i, l, r) for(i=l; i<=r; ++i)
#define lp2(i, r, l) for(i=r; i>=l; --i)
 
typedef long int Int;
typedef long long LL;
 
const Int maxN=(Int)1E5, modbase=(Int)1E9+7;
 
Int n, k, a[maxN], trace[maxN];
double	f[maxN];
LL	answer;
deque<Int> dq;
 
int	main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	Int i;
	while (!dq.empty()) dq.pop_back();
	cin >> a[0]; f[0]=log(a[0]); trace[0]=-1; dq.push_back(0);
	lp1(i, 1, n-1)
	{
		cin >> a[i];
		while (!dq.empty() && i-dq.front()>k) dq.pop_front();
		f[i]=f[dq.front()]+log(a[i]); trace[i]=dq.front();
		while (!dq.empty() && f[i]<=f[dq.back()]) dq.pop_back();
		dq.push_back(i);
	}
	answer=1; 
	for (i=n-1; i>=0; i=trace[i])
	{
		answer*=(LL)a[i];
		answer%=modbase;
	}
	cout << answer;
	return 0;
} 
*/
