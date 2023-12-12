#include<bits/stdc++.h> 
using namespace std; 
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define MAX 1000009
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0); 
int main() 
{ 
	int x=-1;
	cout<<"Before try\n";
	try{
		cout<<"inside try\n";
		if(x<0){
			throw x;
			cout<<"after throw\n";
		}	
	}catch(int x){
		cout<<"exceptin\n";
	}
	cout<<"after catch\n";
	return 0; 

} 

