#include <bits/stdc++.h>
using namespace std;
int max_intersection(int center[],int length,int k){

}
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
    int l,r;cin>>l>>r;
    vector<int> b;
    for(int i=0;i<n;i++){
    	if(i>=l-1 && i<r)
    		continue;
    	else b.push_back(a[i]);
	}
	cout<<b.size()<<'\n';
	for(auto it:b )
		cout<<it<<' ';
}
