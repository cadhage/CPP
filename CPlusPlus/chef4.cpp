#include <bits/stdc++.h>;
using namespace std;
int main(){
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int n;cin>>n;
		int neg=0,pos=0;
		for(int j=0;j<n;j++){
			int x;cin>>x;
			
			if(x>=0)
			pos++;
			else neg++;
		}
		if(neg==0 ||pos==0)
			cout<<max(neg,pos)<<" "<<max(neg,pos);
			else
			cout<<max(neg,pos)<<" "<<min(neg,pos);
	}
	return 0;
}
