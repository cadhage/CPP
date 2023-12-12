#include<bits/stdc++.h>
using namespace std;
void solver(int a[],int n){
	int sol[n];
	for(int i=0;i<n;i++)
		sol[i]=1;
	int prev=0,count=0;
	for(int i=1;i<n-1;i++){
		if(a[i-1]<a[i] && sol[i-1]>=sol[i])
			sol[i]=sol[i-1]+1;
	}
	for(int i=n-2;i>=0;i--){
		if(a[i+1]<a[i] && sol[i+1]>=sol[i])
			sol[i]=sol[i+1]+1;
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=sol[i];
	cout<<sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    int a[t+1];
    for(int i=0;i<t;i++)
    {
   		cin>>a[i];
    }
    solver(a,t);
}
