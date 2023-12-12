#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	while(q-->0){
		int r,g;cin>>r>>g;
		float dp[r+1][g+1];
		for(int i=0;i<=g;i++)
			dp[0][i]=1;
		for(int i=0;i<=r;i++)
			dp[i][0]=1;
		for(int i=0;i<=r;i++)
			for(int j=0;j<=g;j++)
				dp[i][j]=1.0*i/(i+j)+(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))*dp[i][j-2];;
		cout<<setprecision(6)<<dp[r][g];
	}
	return 0;
}
