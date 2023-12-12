#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
bool checkSorted(queue<ll> &q,ll n){
	stack<ll> st;
	int expected=1,fnt;
	vector<ll> v;
	while(!q.empty()){
		fnt=q.front();
		q.pop();
		if(fnt==expected){
			expected++;
			v.push_back(fnt);
		}
		else{
			if(st.empty()){
				st.push(fnt);
			}else if(!st.empty() && st.top()<fnt){
				return false;
			}else st.push(fnt);
		}
		while(!st.empty()&&st.top()==expected){
			st.pop();
			v.push_back(expected);
			expected++;
		}
	}
	if(expected-1==n &&st.empty()){
		for(auto it:v){
			cout<<it<<' ';
		}
		return true;
	}
	return false;
}
int main(){
	queue<ll> q;
	q.push(6),q.push(1),q.push(2),q.push(3),q.push(5);
	ll n=q.size();
	checkSorted(q,n)?cout<<"Yes\n":cout<<"No\n";	
	return 0;
}
