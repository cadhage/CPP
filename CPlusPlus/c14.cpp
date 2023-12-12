#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n,T;
    cin>>T;
    while(T--)
    {
    	int a,n,ans = 1;
    	map <int, int> h;
    	cin>>n;
	    for(int i=0; i<n; i++)
	    {
	    	cin>>a;
//	    	cout<<a<<" ";
	    	h[a] += 1;
	    }
//	    cout<<"\n";
        
        int k=0;
	    int v[5] = {0};
	    int c[5] = {0};
	    for(auto &x: h)
	    {
//	        cout<<x.first<<" "<<x.second<<"\n";
	        
	   		if(c[k] >= n/4)
	   		{
	   			v[k] = x.first;
	   			k++;
	   		}
	   		c[k] += x.second;
	   	}

	    for(int i=0; i<4; i++)
	    	if(c[i] > n/4 || c[i] < n/4)
	    		ans = 0;

	    if(ans)
	    {
		    for(int i=0; i<3; i++)
		    	cout<<v[i]<<" ";
		    cout<<"\n";
		}
		else
			cout<<"-1\n";
	}
}
