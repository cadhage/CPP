#include <bits/stdc++.h>
using namespace std;
int mod(string t,int n){
	int r=0;
	for(int i=0;i<t.size();i++){
		r=r*10+(t[i]-'0');
		r%=n;
	}
	return r;
}
string solver(int n){
	list<string> q;
	set<int> v;
	string t="1";
	q.push_back(t);
	while(!q.empty()){
		t=q.front();
		q.pop_front();
		int rem=mod(t,n);
		if(rem==0)
			return t;
		else if(v.find(rem)==v.end()){
			v.insert(rem);
			q.push_back(t+"0");
			q.push_back(t+"1");
		}
	}
}
int main(){
	int n=12;
	cout<<solver(n);
	return 0;
}
