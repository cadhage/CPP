#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,x;
	cin>>n;
	int a[n];
	int k;cin>>k;
	a[0]=k;
	for(int i=1;i<n;i++){
		int k;cin>>k;
		a[i]=a[i-1]+k;
	//	cout<<a[i]<<" ";
	}
	cin>>q;
	while(q--){
        int x;cin>>x;
        cout<<binary_search(a,a+n,x)<<"\n";
    }
}
