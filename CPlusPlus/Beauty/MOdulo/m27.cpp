#include <bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	while(tt--){
		int sh,sm,eh,em;cin>>sh>>sm>>eh>>em;
		if((em-sm)<0){
			cout<<(eh-sh-1)<<" "<<(60+em-sm)<<'\n';
		}
		else
			cout<<(eh-sh)<<" "<<(em-sm)<<'\n';
	}
	return 0;
}
