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
		for(int i=0;i<n;i++){
			for(int j=0;j<2*n;j++){
					if((j>i) && (j <=2*n-i-2 ))
						printf("#");
					else
					{ 
						printf("*");
					}

			}
			cout<<'\n';
		}
	}
	return 0;
}

