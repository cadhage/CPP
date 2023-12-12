#include <bits/stdc++.h>
using namespace std;
vector<int> dp(1000);
bool solver(long long int n){
	dp[0]=0;dp[1]=1;
	bool flag=false;
	for(int i=2;i<=1000;i++){
		dp[i]=dp[i-1]+i;
		if(dp[i]==n)
			flag=true;
	}
	return flag;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int n;
	cin>>n;
//	for
	cout<<solver(n)<<"\n";
	return 0;
}
