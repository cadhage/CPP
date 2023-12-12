#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int dp[N]={0};
bool solver(int n){
	bool seven=false,zero=false;
	while(n>0){
		int rem=n%10;
		if(rem==7){
			seven=true;
		}
		if(rem==0){
			zero=true;
		}
		n/=10;
	}
	return seven&&!zero;
}
void pre(){
	for(int i=1;i<N;i++){
		dp[i]=dp[i-1]+solver(i);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	pre();
	while(tt--){
		int a,b;cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<'\n';
	}
	return 0;
}
