#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
ll pageFaults(ll a[],ll n,ll k){
	queue<ll> q;
	unordered_set<ll> s;
	int c=0;
	for(int i=0;i<n;i++){
		if(s.size()<k){
			if(s.find(a[i])==s.end()){
				s.insert(a[i]);
				c++;
				q.push(a[i]);
			}
		}else{
			if(s.find(a[i])==s.end()){
				int val=q.front();
				q.pop();
				s.erase(val);
				s.insert(a[i]);
				q.push(a[i]);
				c++;
			}
		}
	}
	return c;
}
int main() 
{ 
    ll pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 
                   2, 3, 0, 3, 2}; 
    ll n = sizeof(pages)/sizeof(pages[0]); 
    ll capacity = 4; 
    cout << pageFaults(pages, n, capacity); 
    return 0; 
} 
