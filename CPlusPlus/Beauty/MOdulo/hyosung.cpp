#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int i=1;
	while(n>=0){
		n=n-i;
		if(n<=0){
			cout<<"Patlu"<<'\n';
			break;
		}
		n=n-2*i;
		if(n<=0){
			cout<<"Motu"<<'\n';
			break;
		}
		i++;
	}
	return 0;
}
