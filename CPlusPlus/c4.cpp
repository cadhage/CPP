#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    //fastio;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,h,y1,y2,l;
    cin>>t;
    while(t--)
    {
    	ll ans=-1,c=0;
        cin>>n>>h>>y1>>y2>>l;
        for(int i=0;i<n;i++)
        {
        	int x,y;cin>>x>>y;
        	if(x==1){
        		if(h-y1<=y){
        			//c++;
        			continue;
				}
				else l--;
			}else{
				if(y<=y2){
					//c++;
					continue;
				}
				else l--;
			}
			if(l==0 && ans==-1){
				ans=i;
			}
		}
		if(ans==-1)
	    	cout<<n<<'\n';
	    else cout<<ans<<'\n';
    }
    return 0;
}
