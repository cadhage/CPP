#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
	return (n==0||n==1)?1:n*factorial(n-1);
}
int main() 
{ 
    int num = 5; 
    printf ("Factorial of %d is %d", num, factorial(num)); 
    return 0; 
} 
