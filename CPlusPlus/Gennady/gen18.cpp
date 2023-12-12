#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum==2*n){
			cout<<n<<'\n';
			continue;
		}
		for(int i=0;i<n;i++){
			if(a[i]==2 && a[n-1-i]==2)
				sum--;
			else break;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
