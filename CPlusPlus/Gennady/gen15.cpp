#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		vector<int> a(n);
		int s=0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(i%2==0)
				s+=a;
			else s=abs(s-a);
		}
		cout<<(s>=k?1:2)<<'\n';
	}
	return 0;
}
