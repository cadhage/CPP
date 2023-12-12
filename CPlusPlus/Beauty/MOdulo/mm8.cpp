#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//vector<int> arr(INT_MAX);
void primeFactors(int n,vector<int> &arr) 
{ 
    while (n%2 == 0) 
    { 
    	arr.push_back(2);
        //printf("%d ", 2); 
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
        	arr.push_back(i);
          //  printf("%d ", i); 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
    	arr.push_back(n);
  //      printf ("%d ", n); 
} 
  
/* Driver program to test above function */
int main() 
{ 
	int tt;cin>>tt;
		while(tt--){
		    int n;cin>>n;
		    vector<int> a(n);
			for(int i=0;i<n;i++){
				cin>>a[i];
			} 
			int x;cin>>x;
			if(x==1)
				cout<<"YES"<<'\n';
		    else {
				vector<int> arr;
		    	primeFactors(x,arr); 
		    	bool flag=false;
		    	for(int i=0;i<n;i++){
		    		for(int j=0;j<arr.size();j++){
		    			if(a[i]==arr[j])
		    			{
		    				flag=true;
		    				break;
						}
					}
					if(flag)
						break;
				}
				if(flag)
					cout<<"YES"<<'\n';
				else cout<<"NO"<<'\n';
			}
	}
    return 0; 
} 
