
// C++ program to find modular inverse of a 
// under modulo m using Fermat's little theorem. 
// This program works only if m is prime. 
#include <bits/stdc++.h> 
using namespace std; 
  
// To compute x raised to power y under modulo m 
int power(int x, unsigned int y, unsigned int m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
void modInverse(int a, int m) 
{ 
    if (__gcd(a, m) != 1) 
        cout << "Inverse doesn't exist"; 
  
    else { 
  
        // If a and m are relatively prime, then 
        // modulo inverse is a^(m-2) mode m 
        cout
             << power(a, m - 2, m); 
    } 
} 
  
// To compute x^y under modulo m 
int power(int x, unsigned int y, unsigned int m) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 
 main()
{
 //   GeneratePrimes();
    int n,k;cin>>n;
	for(int i=0;i<n;i++){
		int x,y,d;cin>>x>>y>>d;
		modInverse(x,d);
	}
	 //cout<<ans;
    return 0;}
//} 
//// Driver Program 
//int main() 
//{ 
//    int a = 5, m = 3; 
//    modInverse(a, m); 
//    return 0; 
//} 
