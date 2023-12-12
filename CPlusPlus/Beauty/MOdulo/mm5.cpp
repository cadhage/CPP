#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	for(int ii=0;ii<tt;ii++){
		int m,n;cin>>m>>n;
		int mx=0;
		vector<vector<string>> sa(n+1);
		for(int k=0;k<=n;k++){
			vector<string> s_a(m);
			for(int i=0;i<m;i++){
				string s;cin>>s;
				s_a[i]=s;
			//	std::cout.width(14); std::cout << std::left<<ss;
			}
			sa[k]=s_a;
		}
		int arr[m];
		for(int j=0;j<m;j++){
			int x=0;
			for(int i=0;i<=n;i++){
				int r=sa[i][j].size();
				x=max(x,r);
			}
			arr[j]=x;
		}
		for(int i=0;i<m;i++){
			cout<<"+";
			for(int j=0;j<=arr[i]+1;j++){
				cout<<"-";
			}
		}
		cout<<"+\n";
		cout<<"| ";
		for(int j=0;j<m;j++){
			std::cout.width(arr[j]); std::cout << std::left<<sa[0][j]<<" | ";
		}
		cout<<'\n';
		for(int i=0;i<m;i++){
			cout<<"+";
			for(int j=0;j<=arr[i]+1;j++){
				cout<<"-";
			}
		}
		cout<<"+\n";
		for(int i=1;i<n;i++){
			cout<<"| ";
			for(int j=0;j<m;j++){
				std::cout.width(arr[j]); std::cout << std::left<<sa[i][j]<<" | ";
			}
		//	j++;
			cout<<'\n';
		}
		    cout<<"| ";
			for(int j=0;j<m;j++){
				std::cout.width(arr[j]); std::cout << std::right<<sa[n][j]<<" |";
			}
		//	j++;
			cout<<'\n';
		for(int i=0;i<m;i++){
			cout<<"+";
			for(int j=0;j<=arr[i]+1;j++){
				cout<<"-";
			}
		}
		cout<<"+";
	}
	return 0;
}
