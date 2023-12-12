#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define ll long long
vector<int> g[10000];
bool mark[1000]={0};
int countCommon(int i,int j){
	int c=0;
	for(int k=0;k<=33;k++){
		c+=__builtin_popcount(g[i][k]&g[j][k]);
	}
	return c;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin>>x;	
			if(x==1){
				int a=j%30;
				int b=j%30;
				g[i][b]|=(1ll<<c);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int c=countCommon(i,j);
			ans+=(c*(c-1))/2;
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}
