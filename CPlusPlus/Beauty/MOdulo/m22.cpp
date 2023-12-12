#include <bits/stdc++.h>
using namespace std;
void solver(int n,int count){
		bool flag=false;
        for(int i=0;i<100000;i++){
			if(n%2==0)
				n/=2;
			else n=3*n+1;
			if(n==1){
				flag=true;
				cout<<"YES";
				break;
			}
		}
		if(!flag)
			cout<<"NO";
}
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int count=0;
		solver(n,count);	
	}

	return 0;
}

