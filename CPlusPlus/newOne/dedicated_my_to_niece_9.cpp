#include <bits/stdc++.h>
using namespace std;
int dp[1000]={0};
int nCrModp(int n,int r,int p){
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=min(i,r);j>0;j--){
			dp[j]=(dp[j]+dp[j-1])%p;
		}
	}
	return dp[r];
}
int main() 
{ 
    int n = 10, r = 2, p = 13; 
    cout << "Value of nCr % p is " << nCrModp(n, r, p); 
    return 0; 
} 
