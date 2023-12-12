#include <bits/stdc++.h> 
using namespace std; 
void countSort(vector<int> &a,int n){
	int max=*max_element(a.begin(),a.end());
	int min=*min_element(a.begin(),a.end());
	int range=max-min+1;
	vector<int> count(range),output(n);
	for(int i=0;i<a.size();i++){
		count[a[i]-min]++;
	}
	for(int i=1;i<count.size();i++){
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--){
		output[count[a[i]-min]-1]=a[i];
		count[a[i]-min]--;
	}   
	for(int i=0;i<n;i++){
		a[i]=output[i];
	}
}
int main() 
{ 
	vector<int> a ={64, 25, 12, 22, 11}; 
	countSort(a, a.size()); 
	cout << "Sorted array: \n"; 
	for(auto it:a){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

