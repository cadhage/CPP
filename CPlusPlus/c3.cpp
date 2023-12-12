#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    //fastio;
    ll t,n,a,b,c,d,p,q,y,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c>>d>>p>>q>>y;
        ll arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ll ans = abs(arr[a-1]-arr[b-1])*p;
        if(abs(arr[a-1]-arr[c-1])*p<=y)
            ans = min(ans,y + abs(arr[d-1]-arr[c-1])*q + abs(arr[b-1]-arr[d-1])*p);
        cout<<ans<<endl;
    }
    return 0;
}
