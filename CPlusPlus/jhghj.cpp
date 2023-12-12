#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll countEggs(ll eggs,ll floors){
	if(floors==0 || floors==1)
		return floors;
	if(eggs==1)
		return floors;
	ll temp,mn=INT_MAX;
	for(int i=1;i<=floors;i++){
		temp=max(countEggs(eggs-1,i-1),countEggs(eggs,floors-i));
		if(temp<mn)
			mn=temp;
	}
	return mn+1;
}
int main(){
	ll eggs = 2;
	ll floors = 10;
	cout<<countEggs(eggs,floors);
	return 0;
}
