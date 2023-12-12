#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007 
#define MAXN   100001 
int c(int n,int k){
	int res=1;
	if(n-k<k)
		k=n-k;
	for(int i=0;i<k;i++){
		res*=(k-i);
		res/=(i+1);
	}
	return res;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    return 0; 
} 
