#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,k,x;cin>>n>>k>>x;
		vector<int> a(k);
		for(int i=0;i<k;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		long long sum=0;
		for(int i=0;i<k;i++)
			sum+=a[i];
		int cur=a[0]+x;
		int ptr=k-1;
		n-=k;
		while(n>0){
			int can=cur-a[ptr];
			can=min(can,n);
			sum+=(long long)((long long)cur+(cur-can+1))*can/2;
			n-=can;
			cur-=can+1;
			ptr--;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
