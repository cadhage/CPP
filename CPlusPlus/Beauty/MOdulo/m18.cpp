#include <bits/stdc++.h>
using namespace std;
void solver(int h,int w,int n){
	if(h<n || w<n)
		cout<<"UPLOAD ANOTHER"<<'\n';
	else if((h>=n || w>=n)&& h==w)
		cout<<"ACCEPTED"<<'\n';
	else 
		cout<<"CROP IT"<<'\n';
}
int main(){
	int n;cin>>n;
	int tt;cin>>tt;
	while(tt--){
		int h,w;
		cin>>h>>w;
		solver(h,w,n);	
	}
	return 0;
}
