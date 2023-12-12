#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		long long n,m;cin>>n>>m;
		vector<string> s(n);
		int any=0;
		vector<int> row(n,0);
		vector<int> col(m,0);
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<m;j++){
				any|=(s[i][j]=='1');
				row[i]|=(s[i][j]=='1');
				col[j]|=(s[i][j]=='1');
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j>0){
					cout<<' ';
				}
				if(!any){
					cout<<-1;
				}
				else{
					if(s[i][j]=='1'){
						cout<<0;
					}
					else {
						if(row[i]||col[j]){
							cout<<1;
						}
						else{
							cout<<2;
						}
					}
				}
			}
			cout<<'\n';
		}
		
	}
}
