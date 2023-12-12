#include <bits/stdc++.h>
using namespace std;
void sub(int a[],int n){
	for(int i=1;i<pow(2,n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j))
				cout<<a[j]<<' ';
		}
		cout<<'\n';
	}
}
int main(){
	int a[]={1,2,3,4};
	sub(a,4);
	return 0;
}
