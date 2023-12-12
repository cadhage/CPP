#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
map<string, pair<int, int> > ptj;
map<string, pair<int, int> > :: iterator it;
//map<string, pair<int, int> > :: iterator it;
string a,b;
int ga,gb;
void testCases(){
	ptj.clear();
	for(int i=0;i<12;i++){
		cin>>a,ga;
		cin>>b;
		cin>>gb>>b;
		if(ga>gb){
			ptj[a].first+3;
			
		}
		else if(ga<gb)
		ptj[b].first+=3;
		else{
			ptj[a].first+=1;
			ptj[b].first+=1;
		}
		ptj[a].second+=ga-gb;
		ptj[b].second+=gb-ga;
		priority_queue<pair<pair<int,int>,string> > pq;
		for(it=ptj.begin();it!=ptj.end();it++){
		pq.push(make_pair(it->second, it->first));
	}
		cout<<pq.top().second<<" ";
		pq.pop();
		cout<<pq.top().second<<endl;
	}
}
int main(){
	int tc;
	cin>>tc;
	for(int c=1;c<=tc;c++)
		testCases();
	return 0;
}
