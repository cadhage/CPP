#include <bits/stdc++.h>

using namespace std;
int solver(vector<long long int> a,long long int n,long long int nod){
	long long int risk=0,non_risk=0,count=0;
	for(auto it:a){
		if(it>=80 || it<=9)
			risk++;
		else non_risk++;
	}
	if(risk%nod==0)
		count+=risk/nod;
	else {
		count+=risk/nod+1;
	}
	if(non_risk%nod==0)
		count+=non_risk/nod;
	else{
		count+=non_risk/nod+1;
	}
	return count;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  while(tt--){
  	long long int n,nod;cin>>n>>nod;
  	vector<long long int> a(n);
  	for(int i=0;i<n;i++)
  		cin>>a[i];
	cout<<solver(a,n,nod)<<'\n';
	}
  return 0;
}

