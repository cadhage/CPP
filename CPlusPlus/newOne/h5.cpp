#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lcm(a,b) ((a*b)/__gcd(a,b))
#define MOD 1000000007
ll fact[1000];
ll pot[1000];
long long powmod(long long a,long long b){
    long long ret = 1;
    while(b){
        if(b&1){
            ret*=a;
            ret%=MOD;
        }
        b>>=1;
        a*=a;
        a%=MOD;
    }
    return ret;
}
int N=1000; 
int fact[N], ifact[N], pow2[N];
     
    void prep() {
      fact[0] = ifact[0] = pow2[0] = 1;
      rep(i, 1, N) {
        fact[i] = mul(fact[i-1], i);
        ifact[i] = inv(fact[i]);
        pow2[i] = mul(pow2[i-1], 2);
      }
    }
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fact[0]=fact[1]=1;
	pot[0]=1;
	pot[1]=2;
	for(int i=2;i<1000;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
		pot[i]=pot[i-1];
		pot[i]%=MOD;
	}
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
        string s;cin>>s;
        if(count(s.begin(),s.end(),'b')){
			cout<<1<<'\n';
			continue;
		}
		vector<ll> v;
		if(s[0]=='a')
			v.push_back(0);
		int i;
		int cnt=0;
		while(i<n){
			if(s[i]=='b'){
			cnt++;
			i++;
			}
			else{
				v.push_back(cnt);
				int j=i;
				while(j<n&&s[j]=='a')
				j++;
				cnt=0;
				i=j;
			}
		}	
	v.push_back(cnt);
	int L=0;
	for(auto i:v){
		L+=i;
	}
	int ans=fact[L];
	for(auto i:v){
		ans=ans*ifact[i]);
	for(int i=v.size()-1;i>=1;i--){
		ans=ans*pow(v[i]-1,2);
	}
	cout<<ans<<'\n';
	}
	return 0;
}
