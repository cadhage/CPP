#include <bits/stdc++.h> 
using namespace std; 
int partition(int a[],int l,int h){
	int piot=a[h];
	int i=(l-1);
	for(int j=l;j<h;j++){
		if(a[j]<piot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[h]);
	return i+1;
}
void quickSort(int a[],int l,int h){
	if(l<h){
		int pi=partition(a,l,h);
		quickSort(a,l,pi-1);
		quickSort(a,pi+1,h);
	}
}
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	quickSort(arr,0, n-1); 
	cout << "Sorted array: \n"; 
	for(auto it:arr){
		cout<<it<<' ';
	}
	cout<<'\n';
	return 0; 
} 

