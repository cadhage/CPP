#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n;cin>>n;
  vector<int> arr;
  while(n>0){
  	arr.push_back(n%10);
  	n/=10;
  }
  vector<int> a(arr.size());
  for(int i=0;i<arr.size();i++)
  	a[i]=arr[arr.size()-i-1];
  int res=INT_MIN,temp1=-1,temp2=-1,index1=-1,index2=-1;
  for(int i=0;i<a.size();i++){
  		temp1=i;
	  	int sum=a[i];
	  	while(i+1<a.size() && a[i+1]>a[i]){
	  		sum+=a[i+1];
			  i++;	
		}
		temp2=i;
		if(sum>res){
			index1=temp1;
			index2=temp2;
			res=sum;
		}
	}
	cout<<res<<":"<<index1+1<<"-"<<index2+1<<'\n';
}
