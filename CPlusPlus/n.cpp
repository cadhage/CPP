#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll minDrops(ll e,ll f){
	if(f==0 || f==1)
		return f;
	if(e==1)
		return f;
	int mn=INT_MAX,temp=0;
	for(int i=1;i<=f;i++){
		temp=max(minDrops(e-1,i-1),minDrops(e,f-i));
		mn=min(temp,mn);
	}
	return mn+1;
}
int main(){
	ll egg=2;
	ll floors=10;
	cout<<minDrops(egg,floors);
}
