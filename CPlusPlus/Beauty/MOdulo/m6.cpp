#include <bits/stdc++.h>
using namespace std;
bool solver(int n){
	int count=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0)
			count++;;
	}
	return count==1?true:false;
}
int main(){
	for(int i=0;i<100;i++)
	if(solver(i))
		cout<<i<<"\n";
	return 0;
}
