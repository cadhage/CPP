#include <bits/stdc++.h>
using namespace std;
void solver(int a[],int b[],int x,int y,int z){
	if(x==1){
		int sum=0;
		for(int i=y-1;i<z;i++){
			if((i+1)%2==0)
				sum+=b[i];
			else sum+=a[i];
			cout<<endl;
		}
		cout<<sum<<endl;
	}
	if(x==2){
		int sum=0;
		for(int i=y-1;i<z;i++){
			if((i+1)%2!=0)
				sum+=b[i];
			else sum+=a[i];
		}
		cout<<sum<<endl;
	}
//	for(int i=0;i<z;i++){
//		cout<<a[i]<<endl;
//	}
}
int main(){
	int n,q;cin>>n>>q;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	while(q-->0){
		int x,y,z;cin>>x>>y>>z;
		solver(a,b,x,y,z);
		//cout<<endl;
	}
	return 0;
}
