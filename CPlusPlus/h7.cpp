#include <bits/stdc++.h>

using namespace std;
vector<bool> prime(100000,true);
void saive(){
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=100000;i++){
		if(prime[i]==true){
			for(int j=i*i;j<=100000;j+=i){
				prime[j]=false;
			}
		}
	}
}
void solver1(vector<int> a,int mn,int mx){
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]*a[j]>=mn && a[i]* a[j]<=mx)
				cout<<a[i]<<','<<a[j]<<'\n';
		}
	}
}
void solver(int x,int y){
	vector<int> vect;
	int mn=(x/2)*(y/2),mx=x*y;
	for(int i=x;i<=y;i++){
		if(prime[i])
			vect.push_back(i);
	}
	solver1(vect,mn,mx);
//	for(auto it:prime){
//		cout<<it<<'\n'
//	}
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x,y;cin>>x>>y;
  saive();
  solver(x,y);
  return 0;
}

