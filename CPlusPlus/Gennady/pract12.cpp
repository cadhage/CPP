#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> v;
int powerSet(int a[],int n){
	long long sum=0;
	for(int i=0;i<(int)pow(2,n);i++){
		vector<int> vect;
		long long mul=1;
		for(int j=0;j<n;j++){
			if((i&(1<<j))!=0){
				//vect.push_back(a[j]);
//				cout<<a[j]<<' ';
				mul*=a[j];
			}
		}
		if(mul!=1)
			sum+=mul;
		//cout<<;
		//v.push_back(vect);
		//vect.clear();
	}
	cout<<sum%1000000007<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	 ll t,n,i,j,k,l,m;

    scanf ("%lld",&n);
    ll arr[n],ans=1;
    for (i=0;i<n;++i)
    {
        scanf ("%lld",&arr[i]);
        ans=(ans*(arr[i]+1))%1000000007;
    }
    ans=(ans-1)%1000000007;
    printf ("%lld\n",ans);
	return 0;
}
