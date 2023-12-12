#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a={1,2,3,4,5};
	cout<<accumulate(a.begin(),a.end(),0)<<'\n';
	return 0;
}
