#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<char> a(n);
	for(int i=0;i<n/2;i++){
		string x;cin>>x;
		a[i]=x[0];
	}
	for(int i=n/2;i<n;i++){
		string x;cin>>x;
		a[i]=x[x.size()-1];
	}
	long long int newOne=0;
	string s;
	for(int i=0;i<n;i++){
		s[i]=a[i];
	}
	newOne=stoi(s);
	newOne%11==0?cout<<"OUI":cout<<"NON";
	return 0;
}
