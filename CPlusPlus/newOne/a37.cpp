#include <bits/stdc++.h>
using namespace std;
void rearange(int a[],int n){
	int p=0,ne=1;
	while(true){
		while(p<n &&a[p]>=0){
			p+=2;
		}
		while(ne<n &&a[ne]<=0){
			ne+=2;
		}
		if(p<n &&ne<n){
			swap(a[p],a[ne]);
		}
		else break;
	}
}
int main(){
	int a[]={1,-3,5,6,-3,6,7,-4,9,10};
	int n=sizeof(a)/sizeof(a[0]);
	rearange(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
