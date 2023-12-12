// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 
int main() 
{ 
	string arr[] ={"ball", "pen", "apple", "kite"};
    sort(arr,arr+4);
	for(auto it:arr){
		cout<<it<<' ';
	} 
	return 0; 
} 

