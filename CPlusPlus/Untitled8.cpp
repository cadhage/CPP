#include <bits/stdc++.h>
using namespace std;
bool coprime(int a, int b) 
{    
    return (__gcd(a, b) == 1); 
} 
int count(int a) 
{    
	int cnt=0;
	for(int i=1;i<floor(sqrt(a));i++){
		if(coprime(a,i))
			cnt++;
	}
	return cnt;
} 
int main(){
	int n,q;cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(q-->0){
		int s,x,y;cin>>s>>x>>y;
		if(s==1){
			int sum=0;
			for(int j=0;j<n;j++){
				if(a[j]>=x && a[j]<=y){
					sum+=count(a[j]);
				}
			}
			cout<<sum<<endl;
		}
		if(s==2){
			a[y-1]=x;
		}
	}
	return 0;
}
