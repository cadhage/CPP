#include <bits/stdc++.h>

using namespace std;
int solver(long long int a,long long int b){
	int count=0;
	if(a==1 || b==1)
		return 1;
	for(int i=1;i<=a*b;i++){
			if((i)%2==0)
				count++;
	}
	return count;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  while(tt--){
  	long long int a,b;cin>>a>>b;
	cout<<solver(a,b)<<'\n';
	}
  return 0;
}

