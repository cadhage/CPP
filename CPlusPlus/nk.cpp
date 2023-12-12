#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n-->0){
		string s;
		cin>>s;
		size_t found = s.find("21"); 
		bool flag=false;
   		if (found != string::npos|| stoi(s)%21==0) 
        	cout<<"The streak is broken!"<<endl;
		else cout<<"The streak lives still in our heart!"<<endl;
	}
	return 0;
}
