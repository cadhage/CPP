#include <bits/stdc++.h>
using namespace std;
bool check(int i){
	while(i>0){
		int res=i%10;
		if(res==4)
			return false;
		i=i/10;
}
	return true;
}
void solver(int n,int tc){
	int i=1,j=n-1;
	while(i<j){
			if(i+j==n &&check(i) && check(j)){
				cout<<"Case #"<<tc+1<<": "<<i<<" "<<j<<"\n";
				break;
		}
		i++;j--;
	}
}
//cout<<diff;
int main(){
	int t;cin>>t;
	for(int i=0;i<t;i++){
		int n;cin>>n;
		solver(n,i);
	}
	return 0; 
}
