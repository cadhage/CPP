#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007 
#define MAXN   100001 
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int lcm(int a,int b){
	extendedEuclid(a,b);
	return a*b/d;
}
int gcd(vector<int> a){		
	int res=a[0];
	for(int i=1;i<a.size();i++){
		res=lcm(res,a[i])%M;
	}
	return res;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<gcd(a);
	}
    return 0; 
} 
