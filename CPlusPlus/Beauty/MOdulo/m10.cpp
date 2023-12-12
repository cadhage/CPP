/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
int solver(int n){
	if(n==0||n==1)
		return 1;
	return n*solver(n-1);
}
int main(){
    int n;cin>>n;
    cout<<solver(n);
	return 0;
}
