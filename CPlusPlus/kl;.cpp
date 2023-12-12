#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;cin>>n>>m;
	char s[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	string ss="saba";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k;
			for(k=0;k<4;k++){
        	{ 
            	if(s[j]== ss[k]) 
                	break; 
        	} 
        	if (k==4) 
            	return false; 
		}
	}
	
	return 0;
}
