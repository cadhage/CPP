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
	int n;cin>>n;
	while(n-->0){
	int q;cin>>q;
	int count=0;
	int prevx=0,prevy=0;
	while(q-->0){
		int x,y;cin>>x>>y;
		if(prevy<x || prevx>y)
			count++;
		prevx=x;
		prevy=y;
		//cout<<endl;
	}
	cout<<count+1<<endl;}
	return 0;
}
