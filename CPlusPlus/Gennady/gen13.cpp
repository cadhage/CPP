#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		int ok=1;
		ok&=a[0]==0;
		ok&=b[n-1]==0;
		ok&=b[0]==a[n-1];
		ok&=b[0]>0;
		set<int> s;
		set<int> must;
		for(int i=1;i<n-1;i++){
			ok&=a[i]>0;
			ok&=b[i]>0;
			ok&=a[i]+b[i]>=b[0];
			if(a[i]+b[i]==b[0])
				s.insert(a[i]);
			else{
				ok&=abs(a[i]-b[i])<=b[0];
				
			}
		}
		cout<<(ok?"Yes":"No")<<'\n';
	}
	return 0;
}
