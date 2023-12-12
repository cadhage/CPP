#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int> p3(n/2+2);
		p3[0]=1;
		for(int i=1;i<(int)p3.size();i++){
			p3[i]=p3[i-1]*3;
		}
		int half=n/2;
		map<long long,int> mp;
		for(int t=0;t<p3[half];t++){
			long long sum=0;
			int tmp=t;
			for(int i=0;i<half;i++){
				sum+=a[i]*(tmp%3-1);
				tmp/=3;
			}
			mp[sum]++;
		}
		long long ans=0;
		for(int t=0;t<p3[n-half];t++){
			long long sum=0,tmp=t;
			for(int i=half;i<n;i++){
				sum+=a[i]*(tmp%3-1);
				tmp/=3;
			}
			ans+=mp[sum];
		}
		cout<<(ans-1)%1000000007<<'\n';
	}
	return 0;
}
