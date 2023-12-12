#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int n;cin>>n;
		int a[n];
		int d[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			cin>>d[j];
		}
		int ans=0;
		for(int j=0;j<n;j++){
		    if(j==0 && a[n-1]+a[(j+1)%n]<d[j])
		        ans=max(ans,d[j]);
			else if(a[j-1]+a[(j+1)%n]<d[j])
				ans=max(ans,d[j]);
		}
		if(ans==0)
			cout<<-1<<"\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}
