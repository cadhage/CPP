#include <bits/stdc++.h>

using namespace std;
void print(vector<int> a){
	for(auto it:a)
		cout<<it<<' ';
}
void printSubsequence(vector<int> arr,int i,vector<int> a){
	if(i==arr.size()){
		print(a);
		cout<<'\n';
	}
	else{
		printSubsequence(arr,i+1,a);
		a.push_back(arr[i]);
		printSubsequence(arr,i+1,a);
		
	}
	return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> arr{1, 2, 3}; 
vector<int> a; 
  printSubsequence(arr,0,a);
  return 0;
}

