#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	while(q-->0){
		int n,maxx,maxy;
		cin>>n>>maxx>>maxy;
		int temp=1;
		while(n-->0){
			int w,b;cin>>w>>b;
			int x[maxy-maxy+1];
			for(int i=maxx;i<=maxy;i++){
				x[i+maxx-1]=i;
			}
			for(int i=maxx;i<=maxy;i++){
				temp=w*x[i+maxx-1]+b;
				x[i+maxx-1]=temp;
				cout<<temp<<endl;
			}
			
		}
		//x=1;
	}	
	return 0;
}
