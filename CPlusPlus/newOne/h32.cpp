#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<vector<int>> g(1000);
bool v[1000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			a[x]=1;a[y]=1;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==1)
			cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
