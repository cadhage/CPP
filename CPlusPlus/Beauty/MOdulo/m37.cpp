#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool lcs( string X, string Y,ll m,ll n )  
{   
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++)
            if(X[i]==Y[j])
                return false;
    }
    return true;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	while(n--){
		string a,b;
		cin>>a>>b;
		bool l=lcs(a,b,a.size(),b.size());
		if(!l){
			cout<<"Yes"<<'\n';	
		}
		else cout<<"No"<<'\n';
	}

	return 0;
}
