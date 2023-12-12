#include <bits/stdc++.h>
using namespace std;
double find_prob(int n,double p){
	double dp[n+1];
	dp[0]=1;
	dp[1]=0;
	dp[2]=p;
	dp[3]=1-p;
	for(int i=4;i<=n;i++){
		dp[i]=(p)*dp[i-2]+(1-p)*dp[i-3];
	}
	return dp[n];
}
int main() 
{ 
    int n = 5; 
    cout << find_prob(n, 0.2) << endl; 
    return 0; 
} 
