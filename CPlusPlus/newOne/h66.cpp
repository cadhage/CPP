// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 
int countFactors(int n) 
{ 
	int count = 0; 
	int sq = sqrt(n); 
	if (sq * sq == n) 
		count++; 
	for (int i=1; i<sqrt(n); i++) 
	{ 
		if (n % i == 0)	 
			count += 2; 
	}		 
	
	return count; 
} 
void printOnBasisOfFactors(int arr[], int n) 
{	 
	pair<int,int> num[n];
	for (int i=0; i<n; i++) 
	{ 
		num[i].first= i; 
		num[i].second = countFactors(arr[i]);		 
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
	int arr[] = {5, 11, 10, 20, 9, 16, 23}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printOnBasisOfFactors(arr, n); 
	return 0; 
} 

