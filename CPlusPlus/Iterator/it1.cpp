#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a={1,2,3,4,5};
	cout<<accumulate(a.begin(),a.end(),0)<<'\n';
	list<int> ll(a.begin(),a.end());
	cout<<accumulate(ll.begin(),ll.end(),0)<<'\n';
	return 0;
}
