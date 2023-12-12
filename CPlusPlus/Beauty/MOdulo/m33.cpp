#include <bits/stdc++.h>
using namespace std;
void solver(string s){
	vector<int> a(26,0);
	for(char c:s){
		a[(int)(c-'a')]++;
	}
	int ans=min(a[(int)('h'-'a')]/2,min(a[(int)('a'-'a')]/2,
			min(a[(int)('c'-'a')],min(a[(int)('k'-'a')],
			min(a[(int)('e'-'a')]/2,min(a[(int)('r'-'a')]/2,
			a[(int)('t'-'a')]))))));
//for(int it:a)
//	cout<<it<<" ";
cout<<ans;
}
int main(){
	int n;cin>>n;
	string s;
	cin>>s;
	solver(s);
	return 0;
}
