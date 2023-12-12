#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int mat[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=0;
		}
	}
	int x,y,impact;cin>>x>>y>>impact;
	mat[x][y]=impact;
//	for(int i=1;i<n;i++){
//		if
//		mat[x-i][y]=impact-i<0?-(impact-i):impact-i;
//		mat[x+i][y]=impact-i<0?-(impact-i):impact-i;
//		mat[x][y+i]=impact-i<0?-(impact-i):impact-i;
//		mat[x][y-i]=impact-i<0?-(impact-i):impact-i;
//	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==impact){
				
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
