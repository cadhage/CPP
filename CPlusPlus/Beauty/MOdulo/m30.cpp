#include <bits/stdc++.h>
using namespace std;
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
int createTable(int s){
	int j=0;
    for(int i=s;i<INT_MAX;i++){
    	if(prime(i))
			return i;
	}
	return -1;
}
int prePrime(int s){
	int j=0;
    for(int i=s;i>=2;i--){
    	if(prime(i))
			return i;
	}
	return -1;
}
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		string s;cin>>s;
		vector<bool> a(s.size(),false);
		for(int i=1;i<s.size();i++){
			if(s[i-1]==s[i])
			{
				a[i-1]=a[i]=true;	
			}	
		}
		for(int i=0;i<s.size();i++){
			int pr1=0;
			if(a[i]){
				pr1=prePrime((int)s[i]);
				cout<<(char)(pr1%256);
			}
			else{
				pr1=createTable((int)s[i]);	
				cout<<(char)(pr1%256);
			}
		}
	}
	return 0;
}
