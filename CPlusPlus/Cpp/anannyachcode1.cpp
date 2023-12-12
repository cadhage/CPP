#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[100];
  for(int i=0;i<100;i++)
  	a[i]=i+1;
  int n=sizeof(a)/sizeof(a[0]);
  int sum=0;
  for(int i=0;i<n;i++){ //loop
  	sum=sum+a[i];
  //	cout<<sum<<'\n';
  }
  cout<<sum<<'\n';
  return 0;
}

