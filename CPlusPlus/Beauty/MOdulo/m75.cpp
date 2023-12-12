#include <bits/stdc++.h>
using namespace std;
bool solver(int r,int x){
	if((2*(22/7)*r)<=100*x)
		return true;
	else return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	int c=0;
	for(int i=0;i<tt;i++){
		int a,b;cin>>a>>b;
		if(solver(a,b))
			c++;//<<'\n';
	}
	cout<<c;
	return 0;
}
