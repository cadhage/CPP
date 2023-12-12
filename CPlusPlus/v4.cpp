#include <bits/stdc++.h>

using namespace std;
void solver(long long int n,long long int k){
	for(int i=k;i<2*k;i++){
		cout<<i/2<<' ';
	}
	cout<<'\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  while(tt--){
  	long long int n,k;cin>>n>>k;
	solver(n,k);
	}
  return 0;
}

