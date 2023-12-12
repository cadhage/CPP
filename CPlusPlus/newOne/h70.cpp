// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 
int main() 
{ 
	vector<int> a ={12, 10, 9, 45, 2, 10, 10, 45,10};
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	cout<<accumulate(a.begin(),a.end(),0)<<'\n';
	return 0; 
} 

