#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	while(q-->0){
		int n;cin>>n;
		int a[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
//			for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				cout<<a[i][j]<<" ";
//			}
			bool flag=false;
			for(int i=0;i<n;i++)
				if(a[i][i]!=0)
					flag=true;
	for(int i=0;i<n;i++){
		int row[n];
		for(int k=0;k<n;k++){
			row[k]=a[i][k];
		}
		int col[n];
		for(int k=0;k<n;k++){
			col[k]=a[k][i];
		}
		bool flag1=false;
		for(int k=0;k<n;k++){
			if(row[k]!=col[k])
				flag1=true;
		}
		if(flag1){
			//cout<<"no";
			flag=true;
			break;
		}
	}
		if(flag)
			cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
