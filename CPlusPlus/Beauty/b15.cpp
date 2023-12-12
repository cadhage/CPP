#include <bits/stdc++.h>
using namespace std;
int maxDifference(int a[],int N,int k){
	int M,S=0,S1=0,max_diffrence=0;
	for(int i=0;i<N;i++){
		S+=a[i];
	}
	sort(a,a+N,greater<int>());
	M=max(k,N-k);
	for(int i=0;i<M;i++){
		S1+=a[i];
	}
	max_diffrence=S1-(S-S1);
	return max_diffrence;
}
int main(){
	int arr[] = { 8, 4, 5, 2, 10 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
    cout << maxDifference(arr, N, k) << endl; 
	return 0;
}
