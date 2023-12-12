#include <bits/stdc++.h> 
using namespace std; 
void countSort(int a[],int n,int exp){
	int count[10]={0},output[n];
	for(int i=0;i<n;i++){
		count[(a[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--){
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++){
		a[i]=output[i];
	}
}
void radixSort(int a[],int n){
	int m=*max_element(a,a+n);
	for(int i=1;m/i>0;i*=10){
		countSort(a,n,i);
	}
}
int main() 
{ 
	int a[] ={64, 25, 12, 22, 11}; 
	radixSort(a,5); 
	cout << "Sorted array: \n"; 
	for(auto it:a){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

