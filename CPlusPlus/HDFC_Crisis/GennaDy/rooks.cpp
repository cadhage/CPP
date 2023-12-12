#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,m;
		cin>>n>>m;
		vector<int> row(n,0);
		vector<int> col(n,0);
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			x--;y--;
			row[x]=col[y]=1;
		}
		cout<<n-m;
		int pr=0,pc=0;
		for(int i=0;i<n-m;i++){
			while(row[pr]==1)
				pr++;
			while(col[pc]==1)
				pc++;
			pr++;
			pc++;
			cout<<" "<<pr<<' '<<pc;
		}
		cout<<'\n';
	}
	return 0;
}
