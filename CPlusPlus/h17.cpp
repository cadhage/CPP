#include <bits/stdc++.h>

using namespace std;
void solver(int a,int b,int n){
	for(int i=0;i<=n;i++){
		if((n-a*i)%b==0){
			cout<<i<<" "<<(n-a*i)/b<<'\n'; 
		}
	}
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solver(2,3,7);
  return 0;
}

