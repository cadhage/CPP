#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,g;cin>>n>>m>>g;
	vector<int> t(n);
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	vector<int> cr(n+1);
	cr[0]=0;
	cr[n]=0;
	for(int i=1;i<n;i++)
	{
	    cr[i]=t[i]-t[i-1];
	}
	sort(cr.begin(),cr.end());
	vector<int> a(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
    int ans=0;
    for(int i=m-1;i>=0;i--)
    {
        if(t[n]>=a[i])
        {   
            ans=i+1;
            break;
        }
    }
    cout<<ans<<'\n';
	return 0;	
}
