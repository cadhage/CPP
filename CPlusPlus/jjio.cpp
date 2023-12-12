#include <bits/stdc++.h>
using namespace std;
int solver(int a[],int s,int e){
	if(s==e-1)
		return 0;
	int size=e;
	int rem=size-s;
	if(rem<=a[s])
		return 1;
	if(a[s]==0)
	{
		cout<<"not possible";
		return INT_MAX;
	}
	int jump=INT_MAX;
	for(int i=1;i<=a[s];i++){
		int temp=solver(a,s+i,e);
		if(temp!=INT_MAX)
			jump=min(jump,1+temp);
		else {
		}
	}
	return jump;
}
int main(){
	 int a[] = {1, 3, 5, 3, 3,1,1,1,1,1,1,1,1,4};
	 int n=sizeof(a)/sizeof(a[0]);
	cout<<solver(a,0,n);
}
