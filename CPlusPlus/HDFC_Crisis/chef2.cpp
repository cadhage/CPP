#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[1000][1000]={0};
ll binomialCoeff(int n,int k){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			if(j==0 ||j==i)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	return dp[n][k];
}

int main(){
	ios_base::sync_with_stdio();
	cin.tie();
	    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int i;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int countprev=0,totcount=0;
        for(i=k-1;i>=0;i--){
            if(a[k-1]==a[i])
            countprev++;
        }
        totcount=countprev;
        for(i=k;i<=n;i++){
            if(a[k-1]==a[i])
            totcount++;
        }
        cout<<binomialCoeff(totcount,countprev)<<endl;
    }  
	return 0;
}
