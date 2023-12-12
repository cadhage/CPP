#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool subset[n+1][sum+1];  
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
     return subset[n][sum]; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum;cin>>sum;
		if (isSubsetSum(a, n, sum)) 
     		printf("YES"); 
 		else
     		printf("NO"); 
	}	
	return 0;
}
