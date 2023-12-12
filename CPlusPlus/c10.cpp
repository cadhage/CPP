#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
string solver(int a[],int n){
	string ans="",ans1="";
	int c=0;bool flag=false;
	fl(i,0,n){
		c++;
		if(c>2 && a[i]+1!=a[i+1]){
			ans+=to_string(a[i]+1-c)+"...";
			ans+=to_string(a[i]);
			flag=true;
			c=0;
		}else if(c<=2){
			ans1+=to_string(a[i])+",";
		}else if(!flag){
			ans+=ans1;
		}
	}
	return ans;
}
int main(){
	ll t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		fl(i,0,n){
			cin>>a[i];
		}
		cout<<solver(a,n);
	}
	return 0;
}
