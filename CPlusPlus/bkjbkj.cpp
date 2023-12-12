#include <bits/stdc++.h>
using namespace std;
void solver(long long n,int tc){
	long long i=1,j=n-1;
	while(i<j){
			string fi=to_string(i);
			string si=to_string(j);
			if(i+j==n && fi.find("4")==-1 && si.find("4")==-1){
				cout<<"Case #"<<tc+1<<": "<<i<<" "<<j<<"\n";
				break;
		}
		i++;j--;
	}
}
//cout<<diff;
int main(){
	int t;cin>>t;
	for(int i=0;i<t;i++){
		long long n;cin>>n;
		solver(n,i);
	}
	return 0; 
}
