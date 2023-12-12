#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
bool sub(string x, string y,
                                 ll m, ll n)
{     
    ll j = 0;
    for (ll i = 0; i < n && j < m; i++)
        if (x[j] == y[i])
            j++; 
    return (j == m);
}
signed main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
    string s;cin>>s;
    ll tt;cin>>tt;
    while(tt--){
        string x;cin>>x;
        if(sub(x,s,x.size(),s.size()))
			cout<<"POSITIVE"<<'\n';
		else 
			cout<<"NEGATIVE"<<'\n';
        
    }
}

