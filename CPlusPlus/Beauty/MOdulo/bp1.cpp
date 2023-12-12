/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n;cin>>n;
    for(int i=2;i<=n;i++)
  		if(prime(i))
			cout<<i<<' ';
	return 0;
}
