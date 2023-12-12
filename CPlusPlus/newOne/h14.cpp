#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;cin>>n;
    vector<string> a;
    for(int i=0;i<=n;i++){
		string s;
		getline(cin,s);
		a.push_back(s);
	}
	int c19=0,c21=0;
	for(auto i:a){
		int found = i.find("19");
  		if (found!=string::npos)
    		c19++;
    	found = i.find("21");
  		if (found!=string::npos)
    		c21++;
	}
	if(c19>=c21)
		cout<<"Date"<<'\n';
	else
		cout<<"No Date"<<'\n';
	return 0;
}

