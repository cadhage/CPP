// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 
int countFactors(int n,int A,int B,int C) 
{ 
	return n*n*A+n*B+C; 
} 
void printOnBasisOfFactors(int arr[], int n,int A,int B,int C) 
{	 
	pair<int,int> num[n];
	for (int i=0; i<n; i++) 
	{ 
		num[i].first= i; 
		num[i].second = countFactors(arr[i],A,B,C);		 
	} 
	sort(num, num+n,[&](auto e1,auto e2){
		if (e1.second == e2.second) 
			return e1.first < e2.first; 
		return e1.second > e2.second;
	}); 
	for (int i=0; i<n; i++) 
		cout << arr[num[i].first] << " "; 
} 
int main() 
{ 
	int arr[] ={-1, 0, 1, 2, 3, 4}; 
    int A = -1, B = 2, C = -1;
	int n = sizeof(arr) / sizeof(arr[0]); 
	printOnBasisOfFactors(arr, n,A,B,C); 
	return 0; 
} 

