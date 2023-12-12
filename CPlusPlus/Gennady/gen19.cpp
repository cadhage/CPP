#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		vector<int> pat(n);
		for(int i=0;i<n;i++){
			cin>>pat[i];
			pat[i]--;
		}
		vector<int> a(n);
		for(int i=0;i<n;i++){
			a[i]=i;
		}
		int ans=0;
		do{
			int ok=1,cc=0;
			for(int i=0;i<n;i++){
				ok&=(pat[i]==-1||pat[i]==a[i]);
			}
			for(int i=0;i<n-1;i++){
				cc+=(a[i]<a[i+1]);
			}
			ans+=(ok&&cc==k);
		}while(next_permutation(a.begin(),a.end()));
		cout<<ans<<'\n';
	}
	return 0;
}
