#include <bits/stdc++.h>

using namespace std;
int countSubSeq(int i,int sum,int cnt,vector<int> a,int n){
  	if(i==n){
  		if(sum==0 && cnt>0)
		  return 1;
		else 
			return 0;	
	}
	int ans=0;
	ans+=countSubSeq(i+1,sum,cnt,a,n);
	ans+=countSubSeq(i+1,sum+a[i],cnt+1,a,n);
	return  ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  cout<<countSubSeq(0,0,0,a,n);
  return 0;
}

