#include <bits/stdc++.h>
using namespace std;
const int md=(int)1e9+7;
inline void add(int &a,int b){
	a+=b;
	if(a>=md)
	a-=md;
}
inline void sub(int &a,int b){
	a-=b;
	if(a<0)
		a+=md;
}
inline int mul(int a,int b){
	return (int)((long long)a*b%md);
}
inline int power(int a,long long b){
	int res=1;
	while(b>0){
		if(b>1){
			res=mul(res,a);
		}
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
inline int inv(int a){
	a%=md;
	if(a<0) a+=md;
	int b=md,u=0,v=1;
	while(a){
		int t=b/a;
		b-=t*a;swap(a,b);
		u-=t*v;swap(u,v);
	}
	assert(b==1);
	if(u<0) u+=md;
	return u;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int MAX=430000;
	vector<int> fact(MAX),inv_fact(MAX);
	fact[0]=inv_fact[0]=1;
	for(int i=1;i<MAX;i++){
		fact[i]=mul(fact[i-1],i);
		inv_fact[i]=inv(fact[i]);
	}
	auto C=[&](int n,int k){
		if(k<0||k>n){
			return 0;
		}
		return mul(fact[n],mul(inv_fact[k],inv_fact[n-k]));
	};
	int tt;cin>>tt;
	while(tt--){
		int n,k;
		cin>>n>>k;
		vector<pair<int,int>> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].first>>a[i].second;
		}
		sort(a.begin(),a.end());
		multiset<int> s;
		int ans=C(n,k);
		for(int i=0;i<n;i++){
			while(!s.empty()&& *s.begin()<a[i].first){
				s.erase(s.begin());
			}
			sub(ans,C((int)s.size(),k-1));
			s.insert(a[i].second);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
