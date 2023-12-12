
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isSubsetSum(int set[], int n, int sum) 
{ 
   // Base Cases 
   if (sum <= 0) 
     return true; 
   if (n == 0 && sum != 0) 
     return false; 
  
   // If last element is greater than sum, then ignore it 
   if (set[n-1] > sum) 
     return isSubsetSum(set, n-1, sum); 
  
   /* else, check if sum can be obtained by any of the following 
      (a) including the last element 
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) ||  
                        isSubsetSum(set, n-1, sum-set[n-1]); 
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
		isSubsetSum(a,n,sum)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
