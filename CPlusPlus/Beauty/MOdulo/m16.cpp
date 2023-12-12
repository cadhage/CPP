#include <bits/stdc++.h>
using namespace std;
void solver(int n){
	vector<int> motu(n+1),patlu(n+1),count(n+1,0);
	bool flag=false;
	for(int i=1;i<=n;i++){
		patlu[i]=i;
		motu[i]=i*2;
		count[i]=count[i-1]+(i+i*2);
		if(count[i-1]<=n && count[i]>n){
			flag=true;
			break;
		}

	}
	
	for(int i=1;i<=n;i++){
		cout<<patlu[i]<< " "<<motu[i]<<" "<<count[i]<<'\n';
	}
}
int main(){
	int n;cin>>n;
	solver(n);
	return 0;
}
