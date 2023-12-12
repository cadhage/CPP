// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 
void solver(int a[],int n) 
{	 
	unique(a,a+n);
	n=sizeof(a)/sizeof(a[0]);
	sort(a,a+n);
	if(n==1)
		cout<<"YES"<<" "<<0<<'\n';
	else if(n==2){
		cout<<"YES"<<" "<<a[1]-a[0]<<'\n';
	}
	else if(n==3){
		if(a[2]-a[1]==a[1]-a[0]){
		cout<<"YES"<<" "<<a[1]-a[0]<<'\n';
		}
		else cout<<"NO"<<"\n";
	}
	else cout<<"NO"<<'\n';
} 
int main() 
{ 
	int arr[] ={55, 52, 52, 49, 52}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	solver(arr,n);
	return 0; 
} 

