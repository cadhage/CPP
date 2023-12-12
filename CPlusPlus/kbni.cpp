#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll q,n,k,ans;
char c;
void solver(char a[]){
	ll ld[n],rd[n],pval=INT_MIN,tval=INT_MIN;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(a[i]=='T' && (pval-i)==k)
			flag=true;
		if(a[i]=='P')
			pval=i;
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]=='T' && (i-tval)==k)
			flag=true;
		if(a[i]=='P')
			tval=i;
	}
	ans+=(tval||pval);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>q;
	while(q-->0){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		char a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		solver(a);
	}
	cout<<ans<<endl;
	}
	
}
