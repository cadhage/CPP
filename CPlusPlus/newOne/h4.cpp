#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int res=0;
	int c1=0,c2=0,c3=0,cb=0;
	for(int i=0;i<n;i++){
		if(a[i]==1) c1++;
		if(a[i]==2) c2++;
		if(a[i]==3) c3++;
		if(a[i]>=3) cb++;
	}
	res += c1 * (c1 - 1) * (c1 - 2) / 6 * 3;
	res += c1 * (c1 - 1) / 2 * c2 * 2;
	res += c1 * (c1 - 1) / 2 * cb;
	res += c1 * c2 * (c2 - 1) / 2;
	res += c1 * c2 * c3;

	cout << res << endl;
	return 0;
}
