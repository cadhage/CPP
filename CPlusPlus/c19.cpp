#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define um unordered_map
#define pr pair
#define mm multimap
#define ms multiset
#define mp make_pair
#define vr vector
int main()
{
    fast;
    ll n,m,i,j,k;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=n/26;
        ll ans=pow(2,k);
        if(n%26==0)
            cout<<0<<" "<<0<<" "<<ans/2;
        else
        {
            m=n%26;
            if(m>=11)
                cout<<0<<" "<<0<<" "<<ans;
            else if(m>=3)
                cout<<0<<" "<<ans<<" "<<0;
            else
                cout<<ans<<" "<<0<<" "<<0;
        }
        cout<<"\n";
    }
}
