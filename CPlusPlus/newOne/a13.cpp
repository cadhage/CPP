#include <bits/stdc++.h>
using namespace std;
void subArrays(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<a[k]<<' ';
			}
			cout<<'\n';
		}
	}
}
int main(){
	int a[]={1,2,3,4};
	int n=4;
	cout<<"All Sub_arrays"<<'\n';
	subArrays(a,n);
	return 0;
}
