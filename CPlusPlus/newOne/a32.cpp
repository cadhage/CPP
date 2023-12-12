#include<bits/stdc++.h>
using namespace std;
void moveZeroToEnd(int a[],int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0)
			swap(a[count++],a[i]);
	}
}
int main(){
	int a[]={0,1,9,8,4,0,0,2,7,0,6,9};
	int n=sizeof(a)/sizeof(a[0]);
	for(int i:a)
		cout<<i<<" ";
	cout<<'\n';
	moveZeroToEnd(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
}
