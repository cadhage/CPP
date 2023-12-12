#include <bits/stdc++.h> 
using namespace std;
void sort(vector<float> &a){
	for(int i=1;i<a.size();i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			j--;	
		}
		a[j+1]=key;
	}
} 
void bucketSort(float a[],int n){
	vector<float> b[n];
	for(int i=0;i<n;i++){
		int bi=n*a[i];
		b[bi].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		sort(b[i]);
	}
	int index=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i].size();j++){
			a[index++]=b[i][j];
		}
	}
}
int main() 
{ 
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr, n); 
	for(auto it:arr){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

