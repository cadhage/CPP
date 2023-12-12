#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void decToHexa(int n) 
{    
    // char array to store hexadecimal number 
    char hexaDeciNum[100]; 
      
    // counter for hexadecimal number array 
    int i = 0; 
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = n % 9; 
        cout<<temp;
        n = n/9; 
    } 
      
    // printing hexadecimal number array in reverse order 
    //for(int j=i-1; j>=0; j--) 
      //  cout << hexaDeciNum[j]; 
} 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	//while(cin>>n){
		decToHexa(100);//<<'\n';
	//}
	return 0;
}
