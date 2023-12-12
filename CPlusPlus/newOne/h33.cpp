#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		sum+=x;
	}
	(sum==2*(n-1))?cout<<"Yes\n":cout<<"No\n";
	return 0;
}
