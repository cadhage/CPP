//a(n) = a(n-1) + a(n-2) + a(n-3) 
//with 
//a(0) = a(1) = 0, a(2) = 1. 
#include <bits/stdc++.h>
using namespace std;
int printTrib(int n) 
{ 
    if (n < 1) 
        return 0; 
  	int curr=0;
    // Initialize first 
    // three numbers 
    int first = 0, second = 0; 
    int third = 1; 
  
    curr=first;
    if (n > 1) 
        curr=second; 
      
    if (n > 2) 
        curr=second; 
  
    // Loop to add previous  
    // three numbers for 
    // each number starting  
    // from 3 and then assign 
    // first, second, third 
    // to second, third, and  
    // curr to third respectively 
    //int curr=0;
    for (int i = 3; i < n; i++)  
    { 
        curr = first + second + third; 
        first = second; 
        second = third; 
        third = curr; 
  
      //  cout << curr << " "; 
    } 
    return curr;
} 
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
	//	for(int i=0;i<=k*k;i++)
		cout<<printTrib(k+4)<<endl;
	}
	return 0;
}
