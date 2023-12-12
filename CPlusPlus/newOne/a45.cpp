// cpp program to calculate the number 
// pairs satisfying th condition 
#include <bits/stdc++.h> 
using namespace std; 

// function to calculate the number of pairs 
int countPairs(int a[], int n, int x, int k) 
{ 
	sort(a, a + n);	 

	// traverse through all elements 
	int ans = 0; 
	for (int i = 0; i < n; i++) { 

		// current number's divisor 
		int d = (a[i] - 1) / x; 

		// use binary search to find the element 
		// after k multiples of x 
		int it1 = lower_bound(a, a + n, 
						max((d + k) * x, a[i])) - a; 

		// use binary search to find the element 
		// after k+1 multiples of x so that we get 
		// the answer bu subtracting 
		int it2 = lower_bound(a, a + n, 
					max((d + k + 1) * x, a[i])) - a; 

		// the difference of index will be the answer 
		ans += it2 - it1; 
	} 
	return ans; 
} 

// driver code to check the above fucntion 
int main() 
{ 
	int a[] = { 1, 3, 5, 7 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int x = 2, k = 1; 

	// function call to get the number of pairs 
	cout << countPairs(a, n, x, k); 
	return 0; 
} 

