#include <bits/stdc++.h>
using namespace std;
int  mat[1000][1000]={0};
void solver(int n)
{
	for(int c=0;c<n/2;c++){
		int i;
		for(i=1;i<=n;i++){
			mat[c][i-1]=i;
			//cout<<'\n';
		}
		cout<<'\n';
		for(int j=1;j<n;j++){
			mat[j][n-1]=i++;
		}    
		for(int j=n-2;j>=0;j--){
			mat[n-1][j]=i++;
		}
		for(int j=n-2;j>0;j--){
			mat[j][c]=i++;
		}
	}
	for(int r=0;r<n;r++){
		for(int c=0;c<n;c++){
			cout<<mat[r][c]<<' ';
		}
		cout<<'\n';
	}
} 	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	solver(n);
	return 0;
}
